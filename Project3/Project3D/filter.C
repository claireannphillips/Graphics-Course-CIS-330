#include "source.h"
#include "sink.h"
#include "filter.h"
#include <stdio.h>

void Shrinker::Execute() {
    //we have pointers now to img so no more . we use the -> for pointer
	int width  = img1->getWidth();
	int height = img1->getHeight();
    //halfw and halfh are too confusing just type out word claire lol
	int halfWidth  = width/2;
	int halfHeight = height/2;
	
	img.ResetSize(halfWidth, halfHeight);

	unsigned char *hold = (unsigned char *) malloc(halfWidth*halfHeight*3);
    //have to give it a type unsigned char

	for (int i = 0; i<halfHeight; i++) {
		for (int j=0; j<halfWidth; j++) {
			int in  = 3 * (i * 2 * width + j * 2);
			int out = 3 * (i * halfWidth + j);
			hold[out] = img1->getData()[in]; //red
			hold[out+1] = img1->getData()[in+1]; //green
			hold[out+2] = img1->getData()[in+2]; //blue
		}
	}
	
	img.setData(hold);
}

void LRCombine::Execute() {
	int width1  = img1->getWidth();
	int height1 = img1->getHeight();
	int height2 = img2->getHeight();
    int width2  = img2->getWidth();

	int outWidth  = width1 + width2;
	int outHeight = (height1 + height2)/2;

	img.ResetSize(outWidth, outHeight);
	
	unsigned char *tempLR = (unsigned char *) malloc(outWidth*outHeight*3);
    //one to fill the squares and the other for loop to fill them	
	for (int i = 0; i < width1; i++) {
		for (int j = 0; j < outHeight; j++) {
			int in  = (j * width1 + i) * 3;
			int out = (j * outWidth + i) * 3;
			tempLR[out] = img1->getData()[in];
			tempLR[out + 1] = img1->getData()[in + 1];
			tempLR[out + 2] = img1->getData()[in + 2];
		}
	}

	for (int i = 0; i < width2; i++) {
		for (int j = 0; j < outHeight; j++) {
			int in2 = (j * width2 + i) * 3;
			int out = (j * outWidth + width1 + i) * 3;
			tempLR[out] = img2->getData()[in2];
			tempLR[out + 1] = img2->getData()[in2 + 1];
			tempLR[out + 2] = img2->getData()[in2 + 2];
		}
	}
    //we refrence img
	img.setData(tempLR);
}

void TBCombine::Execute() {
	int width1  = img1->getWidth();
	int width2  = img2->getWidth();
	int height1 = img1->getHeight();
	int height2 = img2->getHeight();
	int outWidth  = (width1 + width2)/2;
	int outHeight = height1 + height2;
	
	img.ResetSize(outWidth, outHeight);

	unsigned char *tempTB = (unsigned char *) malloc(outHeight*outWidth*3);

	for (int i = 0; i < outWidth; i++) {	
		for (int j = 0; j < height1; j++) {
			int in  = (j * width1 + i) * 3;
			int out = (j * outWidth + i) * 3;
			tempTB[out] = img1->getData()[in];
			tempTB[out + 1] = img1->getData()[in + 1];
			tempTB[out + 2] = img1->getData()[in + 2];
		}
	}
	
	for(int i = 0; i < outWidth; i++) {
		for(int j = 0; j < height2; j++)  {
			int in2 = (j * width2 + i) * 3;
			int out = ((j + height1) * outWidth + i) * 3;	
			tempTB[out] = img2->getData()[in2];
			tempTB[out + 1] = img2->getData()[in2 + 1];
			tempTB[out + 2] = img2->getData()[in2 + 2];
		}
	}
	
	img.setData(tempTB);
}

void Blender::Execute() {
	int width1  = img1->getWidth();
	int width2  = img2->getWidth();
	int height1 = img1->getHeight();
	int height2 = img2->getHeight();
	int outWidth  = (width1 + width2)/2;
	int outHeight = (height1 + height2)/2;
	
	img.ResetSize(outWidth, outHeight);
	
	unsigned char *tempBlend = (unsigned char *) malloc(outHeight*outWidth*3);

    //why dont we have to initialize factor? we already did in our filter.h 	
	
	for(int i = 0; i < outWidth; i++) {	
		for(int j = 0; j < outHeight; j++) {
			int index = (j * outWidth + i) * 3;
			tempBlend[index] = img1->getData()[index]*factor + img2->getData()[index]*(1-factor);
			tempBlend[index+1] = img1->getData()[index+1]*factor + img2->getData()[index+1]*(1-factor);
			tempBlend[index+2] = img1->getData()[index+2]*factor + img2->getData()[index+2]*(1-factor); 
		}
	}
	
	img.setData(tempBlend);
}


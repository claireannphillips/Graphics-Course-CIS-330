#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <functions.h>

void ReadImage(char *filename, Image &output)
{
	char magicNum[128];
	int width, height, maxval;
	FILE *f_in;
	f_in = fopen(filename, "r");
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	unsigned char *hold = (unsigned char*) malloc(sizeof(unsigned char)*3*height*width);
	if(f_in != NULL){
		output.ResetSize(width, height);
	}

	fread(hold, sizeof(unsigned char)* 3, width*height, f_in);
	output.setData(hold);
	fclose(f_in);
}

void WriteImage(char *filename, Image &img)
{
	FILE *w;
	w = fopen(filename, "w");
	int width;
	int height;
	int maxVal;
	fwrite("P6\n", 3,1,w);
	fprintf(w, "%d %d\n", img.getWidth(), img.getHeight());
	fprintf(w, "255\n");
	fwrite(img.getData(), sizeof(unsigned char)*3, img.getWidth() * img.getHeight(), w);
}

void HalfSize(Image &input, Image &output){
	int in, out;
	//getter functions
	int width = input.getWidth();
	int height = input.getHeight();
	int halfw = width/2;
	int halfh = height/2;
	//ressetting the width and height to half 
	output.ResetSize(halfw, halfh);
	unsigned char *hold = (unsigned char*) malloc(sizeof(unsigned char)*3*halfw*halfh);
	//tried new but in assignment have to give it a type of unsigned char and use malloc
	for(int i=0; i<halfh; i++){
		for(int j=0; j<halfw; j++){
			out = 3*((i*halfw)+j);
			//half of the width and times three for the streams of colors. 
			in = 3*((2*i*width)+2*j);
			//in set to original width
			hold[out] = input.getData()[in]; //red. getData returns the buffer of original from in
			hold[out+1] = input.getData()[in + 1]; //green
			hold[out + 2] = input.getData()[in + 2];//blue
		}
	}
	output.setData(hold);
}

void LeftRightCombine(Image &leftInput, Image &rightinput, Image &output){
	int width1 = leftInput.getWidth();
	int height1 = leftInput.getHeight();	
	int width2 = rightinput.getWidth();
	int height2 = rightinput.getHeight();	
	int outWidth = width1 + width2;
	int outHeight = (height1 + height2)/2;
	
	output.ResetSize(outWidth, outHeight);
	
	unsigned char *temp = (unsigned char*) malloc(outWidth * outHeight *3);
	//two for loops to copy one square then another one to fill one square then another one. h*two(height)	
	for(int i = 0; i<width1; i++){
		for(int j = 0; j<outHeight; j++){
			int out = (j*outWidth + i)*3;
			//row*image's width + column * three
			int in = (j*width1 + i)*3;
			temp[out] = leftInput.getData()[in];	
			temp[out+1] = leftInput.getData()[in+1];	
			temp[out+2] = leftInput.getData()[in+2];	
		}
	}
	for(int i = 0; i<width2; i++){
		for(int j = 0; j<outHeight; j++){
			int out = (j*outWidth + width1 + i)*3;
			int in = (j*width2 + i)*3;
			temp[out] = rightinput.getData()[in];	
			temp[out+1] = rightinput.getData()[in+1];	
			temp[out+2] = rightinput.getData()[in+2];	
		}
	}
	output.setData(temp);
}

void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output){
	//same but copy to itself on top and bottom
	//so instead of putting it on the left we put it right under each other
	int width1 = topInput.getWidth();
	int height1 = topInput.getHeight();
	int width2 = bottomInput.getWidth();
	int height2 = bottomInput.getHeight();
	int outHeight = height1 + height2;
	int outWidth = (width1 + width2)/2;
	
	output.ResetSize(outWidth, outHeight);
	
	unsigned char* temp = (unsigned char*) malloc(outHeight*outWidth*3);
	
	for(int i = 0; i<outWidth; i++){
		for(int j = 0; j<height1; j++){
			int out = (j*outWidth+ i)*3;
			int in = (j*width1 + i)*3;
			temp[out] = topInput.getData()[in];	
			temp[out+1] = topInput.getData()[in+1];	
			temp[out+2] = topInput.getData()[in+2];	
		}
	}
	for(int i = 0; i<outWidth; i++){
		for(int j = 0; j<height2; j++){
			int out = ((j+height1)*outWidth+ i)*3;
			int in = (j*width2 + i)*3;
			temp[out] = bottomInput.getData()[in];	
			temp[out+1] = bottomInput.getData()[in+1];	
			temp[out+2] = bottomInput.getData()[in+2];	
		}
	}
	output.setData(temp);
}
void Blend(Image &input1, Image &input2, double factor, Image &output){
	//pixel by pixel so say image one is eighty percent we store in double because more percise than float
	//then image two is twenty percent so create factor that is double factor = .eight
	//then 100-.8 is 20% that we want 
	int width1 = input1.getWidth();
	int height1 = input1.getHeight();
	int width2 = input2.getWidth();
	int height2 = input2.getHeight();
	int outHeight = (height1 + height2)/2;
	int outWidth = (width1 + width2)/2;
	double f = factor;
	
	output.ResetSize(outWidth, outHeight);
	
	unsigned char* temp = (unsigned char*) malloc(outHeight*outWidth*3);
	
	for(int i = 0; i<outWidth; i++){
		for(int j = 0; j<outHeight; j++){
			int index = (j*outWidth+ i)*3;
			temp[index] = input1.getData()[index]*f+ input2.getData()[index]*(1.0-f);	
			temp[index+1] = input1.getData()[index+1]*f+ input2.getData()[index+1]*(1.0-f);	
			temp[index+2] = input1.getData()[index+2]*f+ input2.getData()[index+2]*(1.0-f);	
		}
	}
	output.setData(temp);
}

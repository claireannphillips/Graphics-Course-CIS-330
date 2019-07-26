#include "sink.h"
#include "image.h"

//2 image pointers since 2 inputs. Comes from Sources
//void sink::SetInput(Image *image1) {
	//img1 = image1;
//	img1 = NULL;
//	img2 = NULL;
//}

//sink writes data so we are writing 2 images to be NULL and we create these images from image.h thats why we have Image *image1)
//constructor because we constructed this function in the .h file
sink::sink(){
	img1 = NULL;
	img2 = NULL;
}

sink::~sink(){}

void sink::SetInput(Image *image1){
	img1 = image1;
}

void sink::SetInput2(Image *image2) {
	img2 = image2;
}


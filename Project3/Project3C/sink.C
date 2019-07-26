#include "sink.h"
#include "image.h"

//2 image pointers since 2 inputs. Comes from Sources
void sink::SetInput(Image *image1) {
	img1 = image1;
}

void sink::SetInput2(Image *image2) {
	img2 = image2;
}


#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Image::Image(void) {
	height = 0;
	width  = 0;
	buffer = NULL;
}

Image::Image(int h, int w, unsigned char *b) {
	height = h;
	width  = w;
	buffer = (unsigned char *) malloc(3*height*width);
	memcpy(buffer, b, 3*height*width); 
}

Image::Image(const Image &img) {
	buffer = (unsigned char *) malloc(3*height*width);
	height = img.height;
	width  = img.width;
	memcpy(buffer, img.buffer, 3*height*width);
}

void Image::ResetSize(int w, int h) {
	this->width = w;
	this->height = h;
}

void Image::setData(unsigned char *b) {
	if (buffer == NULL) {
		buffer = (unsigned char *) malloc(3*height*width);
	}
	memcpy(buffer, b, 3*height*width);
}

int Image::getWidth() {return this->width;};

int Image::getHeight() {return this->height;};

unsigned char * Image::getData() {return this->buffer;};

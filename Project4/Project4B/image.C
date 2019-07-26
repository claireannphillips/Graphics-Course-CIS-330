#include "image.h"
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//source creates an output and we have to include image.h to create an image

void Image::Update(){
	//have to use arrow because it is a pointer the update method in source.h
	source->Update();
}

Image::Image(void) {
	//default constructor
	height = 0;
	width  = 0;
	buffer = NULL;
}

Image::Image(int h, int w, unsigned char *b) {
	//for paramaterized constructor can just assign values
	height = h;
	width  = w;
	buffer = (unsigned char *) malloc(3*height*width);
	memcpy(buffer, b, 3*height*width); 
}

Image::~Image(){
	free(buffer);
}

Image::Image(Image &img) {
	//for our copy constructor can use img. because we have the address so 
	//can get the value with .
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

void Image::setSource(Source *s){
	if(s != NULL){
		source = s;
	}
}

int Image::getWidth() {return this->width;};

int Image::getHeight() {return this->height;};

unsigned char * Image::getData() {return this->buffer;};

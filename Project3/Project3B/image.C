#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

Image::Image(void){
	height = 0;
	width = 0;
	buffer = NULL;
}

Image::Image(int w, int h, unsigned char *b) {
	width = w;
	height = h;
	buffer = (unsigned char*) malloc(3*height*width);
	printf("Paramaterized image constructor is called \n");
	memcpy(buffer, b, width * height * 3 * sizeof(unsigned char));
}

Image::Image(const Image &i){
	width = i.width;
	height = i.height;
	buffer = (unsigned char*) malloc (3*height*width);
	memcpy(buffer, i.buffer, width * height * 3 * sizeof(unsigned char));
	printf("Copy Image constructor is called \n");
}

void Image::ResetSize(int width, int height){
	this->width = width;
	this->height = height;
}

void Image::setData(unsigned char *b){
	if(buffer == NULL)
		buffer = (unsigned char*) malloc (3*height*width);
	memcpy(buffer, b, width * height * 3 * sizeof(unsigned char));
}

int Image::getHeight(){
	return height;
}

int Image::getWidth(){
	return width;
}

unsigned char* Image::getData(){
	return buffer;
}

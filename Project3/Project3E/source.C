#include "image.h"
#include "source.h"
//source creates an output and getOutput returns an image 
Source::Source(){
	//calls the source constructor in source.h
	img.setSource(this);
}

Source::~Source(){}

//data member that is an image
Image * Source::GetOutput() {
	//returns the image 
	return &img;
}

void Source::Update(){
	//execute opens the file and is PNMreader
	Execute();
}


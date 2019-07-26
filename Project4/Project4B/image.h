#include <stdlib.h>
#include <stdio.h>
#ifndef IMAGE_H
#define IMAGE_H
//had help from Alison, Brent, and Yao! 

class Source;
//source is what produces data so we will create an output in the end

class Image {
	private:
		int height, width;
		unsigned char *buffer;
		Source *source;

	public:
		Image(void);
		//default constructor
		Image(int height, int weight, unsigned char *buffer);
		//paraaterized constructor
		Image(Image &img);
		//copy constructor
		~Image();
		void ResetSize(int w, int h);
		void setData(unsigned char *b);
		void setSource(Source *s);
		int getWidth();
		int getHeight();
		unsigned char *getData();
		void Update();
};

#endif


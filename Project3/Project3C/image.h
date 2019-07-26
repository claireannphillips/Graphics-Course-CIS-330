#include <stdlib.h>
#include <stdio.h>
#ifndef IMAGE_H
#define IMAGE_H
//had help from Alison, Brent, and Yao! 

class Image {
	private:
		int height, width;
		unsigned char *buffer;

	public:
		Image(void);
		Image(int height, int weight, unsigned char *buffer);
		Image(const Image &img);

		void ResetSize(int w, int h);
		void setData(unsigned char *b);
		int getWidth();
		int getHeight();
		unsigned char *getData();
};

#endif


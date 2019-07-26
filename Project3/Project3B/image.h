#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef IMAGE_H
#define IMAGE_H

class Image {
	private:
		int width;
		int height;
		unsigned char *buffer;
	public:
		Image(void);
		Image(int w, int h, unsigned char *b);
		Image(const Image &i);
		void ResetSize(int width, int height);

		void setData(unsigned char *b);
		int getWidth();
		int getHeight();
		unsigned char* getData();
};

#endif

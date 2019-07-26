#include "image.h"
#include <string.h>
#ifndef SINK_H
#define SINK_H

class sink {
	protected:
		//2 image pointers bc some filters take 2 inputs
		//Image *img1, *img2;
		Image *img1;
		Image *img2;
	public:
		//set with SetInput and SetInput2
		////points at images that come from Sources
		sink();
		virtual ~sink();
		void SetInput(Image *img1);
		void SetInput2(Image *img2);
};

#endif

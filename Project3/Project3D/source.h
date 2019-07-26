#include "image.h"
#include <stdlib.h>
#include <string.h>
#ifndef SOURCE_H
#define SOURCE_H

class source {
	//data member that is an image
	protected:
		Image  img;
	public:
		//pure virtual function called Execute
		virtual void Execute() = 0;
		//method called GetOutput that returns a pointer to its Image data member
		Image * GetOutput();
};

#endif


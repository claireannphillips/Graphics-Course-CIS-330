#include "image.h"
#include <stdlib.h>
#include <string.h>
#ifndef SOURCE_H
#define SOURCE_H

class Source {
	//data member that is an image
	protected:
		//create an image from image.h 
		Image  img;
		virtual void Execute() = 0;
	public:
		Source();
		~Source();
		Image * GetOutput(void);
		//pure virtual function called Execute
		//virtual void Execute() = 0;
		//method called GetOutput that returns a pointer to its Image data member
		//Image * GetOutput(void);
		virtual void Update();
};
//we include source.h file in filter.C get there is no member GetOutput
#endif


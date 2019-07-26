#include "sink.h"
#include <stdio.h>
//includes sink.h which writes us an image becuase it includes image.h
//so in the PNMwriter.C file we can make that image and we use img -> because its a pointer
//to an image
class PNMwriter : public sink {
	public:
		//the file filename that we are gonig to pass in
		void Write(char *filename);
};


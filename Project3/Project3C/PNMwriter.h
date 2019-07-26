#include "sink.h"
#include <stdio.h>

class PNMwriter : public sink {
	public:
		//the file filename that we are gonig to pass in
		void Write(char *filename);
};


#include "source.h"
#include <stdio.h>

//just need to change it to our new function CPP
class PNMreaderCPP : public source { 
	protected:
		char *filefromh;
	public:
		//now we need to call PNMreaderCPP
		PNMreaderCPP(char *file){
			filefromh = (char *) malloc(strlen(file)+1);
			strcpy(filefromh, file);
		}
	//just need to change reader to the CPP we made		
	~PNMreaderCPP() {
		free(filefromh);
	}

	virtual void Execute();
};


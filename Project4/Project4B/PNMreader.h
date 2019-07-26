#include "source.h"
#include <stdio.h>

//needs to read the file with its execute
class PNMreader : public Source 
{
	private:
		//need to give it filename ahead of time since execute takes no arguments
		//need to put it in constructor
		//can call filefromh instead of filename becasue this is linked to source.h which is
		//linked to image.h where they both don't use filename
		char *filefromh;
	public: 
		PNMreader(char *file);
		~PNMreader();
		//deconstructor to free the memory
		/////////////////free(filefromh);
		virtual void Execute();
	
	//virtual void Execute();
	//calling a virtual function and This denotes the C++  virtual function 
};




#include "source.h"
#include <stdio.h>

//needs to read the file with its execute
class PNMreader : public source 
{
	private:
		//need to give it filename ahead of time since execute takes no arguments
		//need to put it in constructor
		char *filefromh;
	public: 
		PNMreader(char *file);
	~PNMreader(){
		//deconstructor to free the memory
		free(filefromh);
	}
	virtual void Execute();
	//calling a virtual function and This denotes the C++  virtual function 
};




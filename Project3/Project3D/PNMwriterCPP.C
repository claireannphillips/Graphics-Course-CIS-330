#include "PNMwriterCPP.h"
#include <iostream>
#include <fstream>

using namespace std;

void PNMwriterCPP::Write(char *filename){
	//we need to give a stream so name it whatever
	//recieved help from joe and alison
	ofstream s_try;
	int width;
	int height;
	width = img1->getWidth();
	height = img1->getHeight();

	s_try.open(filename, ios::binary);
	//new data will be written to the end of the file 

	s_try << "P6" <<endl;
	//endl inserts a new line 
	//writting to the file so we need the P6 for the beginning of the file
	s_try << width << " " << height << endl;
	//endl also flushes the stream
	//writting to the file. Kind of like replacing those fprints and fwrites
	s_try << 255 <<endl;
	//putting the 255 in the file

	s_try.write((char *) img1->getData(), width * height * 3);
	//writing the data 

	s_try.close();
}


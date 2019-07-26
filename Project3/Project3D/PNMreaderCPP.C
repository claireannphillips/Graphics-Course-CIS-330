#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "PNMreaderCPP.h"

using namespace std;
//using: you are going to use it
//namespace: To use what? A namespace
//std: The std namespace where in C++ standard library string and vector are declared
//so haves_try add the stdlib

void PNMreaderCPP::Execute(){
	ifstream s_try;
	//can name this stream anything

	s_try.open(filefromh, ios::binary);

	char magicNum[128];
	int width;
	int height;
	int maxVal;

	s_try >> magicNum >> width >>height >>maxVal;
	img.ResetSize(width, height);

	unsigned char *hold = (unsigned char *) malloc(3*height*width+1);
	s_try.read((char *) hold, width * height *3);
	img.setData((unsigned char *) hold +1);

	s_try.close();
	free(hold);
}

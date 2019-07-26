#include "PNMreader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
PNMreader::PNMreader(char *file){
	//copy and reader is dreived from reader
	filefromh = (char *) malloc(strlen(file)+1);
	strcpy(filefromh, file);
}

void PNMreader::Execute() {
	//use our reader from 3B and make sure to free the memory so free whatever you malloc
	//we open the file from above
	FILE *w;
	w = fopen(filefromh, "rb");
	char magicNum[128];
	int width;
	int height;
	int maxVal;

	fscanf(w, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxVal);
	
	unsigned char *hold = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
	fread(hold, sizeof(unsigned char) * 3, width * height, w);
	img.ResetSize(width, height);
	img.setData(hold);
	fclose(w);
	//we care about free this project from docs but normally it can free on its own.
	free(hold);

}


#include <PNMwriter.h>
#include <stdio.h>

void PNMwriter::Write(char *filename) {
	//this will be same as our write but we need to make sure we use the pointer -> instead of .
	//we grab this from the PNMwriter.h where write is public
	FILE *w; 
	w = fopen(filename, "w");
	fwrite("P6\n",3,1,w);	
	fprintf(w, "%d %d\n", img1->getWidth(), img1->getHeight());
	fprintf(w, "255\n");
	fwrite(img1->getData(), sizeof(unsigned char)*3, img1->getWidth()*img1->getHeight(), w);
	fclose(w);
}

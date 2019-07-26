#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("incorrect number of arguments\n");
		exit(2); //terminate indicate error 
	}
	FILE * f; //file pointer
	FILE * w; //file pointer
	int save;
	int r; //returns number of objects read or written
	if((f = fopen(argv[1], "r")) == NULL){ 
        //checking to make sure not null and setting variable f to the first input file
		exit(2);
	}
	if((w = fopen(argv[2], "w")) == NULL){
    //checks file and if something is there it will return a pointer and if not then will return null so checking that		
    //setting w to the second argument file
        fclose(f);
		exit(2);
	}
	for(int i = 0; i < 5; i++){
        //i*40 because thats a row and seek set goes to very beginning of file so i*40 is offset of row we want
		int row_index = i * 40; //0 * 40 is 0 so beginning
		fseek(f, row_index, SEEK_SET); //seek_set is beginning of file		
        //pointer of fseek is left in f so next for loop the cursor is where we wnat to grab those ints.

		for(int j = 0; j  < 5; j++){
            //this 2nd for loop is to read each box of the 5x5 and save it into a pointer to write into the w file
			r = fread(&save, 4, 1, f);	//4 bytes that represent 1 bit since byte is 8 bits. 1 int is 32 bits. First param is pointer
             //going to read from f. r stores how many objects we read. Read from f, objects size of 4 and read this many which is 1 and
            //save those into save. If we print out r it would be 1 each time since reading 1 integer at a time.
			fprintf(w, "%d\n", save); //file, %d for decimal, save so writing whats in save into the w file in this format. 
            //same as printf but fprint f saves it to the file w.  
		}

	}
	fclose(f);
	fclose(w);
	return 0;
}

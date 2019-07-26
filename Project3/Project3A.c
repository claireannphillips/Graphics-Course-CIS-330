#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
 {
/* data members go here */
    int width;
    int height;
    unsigned char *buffer; //give it the pointer to buffer in memory 
} Image;

Image *
ReadImage(char *filename)
{
    char magicNum[128]; //given
    int width, height, maxval;//given
    FILE * f_in;
    f_in = fopen(filename, "r");
    Image* i = malloc(sizeof(Image));//i is the pointer and struct is the image
    fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);  //given
    //printf("f_in = %p\n", f_in);
    //printf("width, height = %d,%d\n", width,height);
    //printf( "%d %d\n", magicNum, width, height, maxval);
    //save the values we just got into the struct
    //need to store the values of image in the struct so can actually read it
    if (f_in != NULL){
        i = malloc(sizeof(Image));//i is the pointer and struct is the image
        i->width = width;
        i->height = height;
        i->buffer = malloc(width*height*3*sizeof(unsigned char));
        //put buffer on heap so we know what the buffer size is so can access it
        //buffer is dependent on width and height. it is storing the data so need to create size of buffer.
    } 
    //printf( "%d %d\n", width, height);
    fread(i->buffer, 3, width*height, f_in);
    fclose(f_in);
    return i;
}


void WriteImage(Image *img, char *filename)
{
    FILE * w;
    w = fopen(filename, "w");
    fwrite("P6\n",3,1,w);
    fprintf(w, "%d %d\n", img->width, img->height);
    fprintf(w, "255\n");
    fwrite(img->buffer,3,img->width * img-> height,w); //want to do width * height amount of pixels and 3 channels
    //buffer is already apointer
}

Image *
YellowDiagonal(Image *input)
{
    Image* output = malloc(sizeof(Image)); //returns the memory for an image. output is a pointer to that memory
    output->width = input->width;
    output->height = input->height;
    output->buffer = malloc(output->width*output->height*3*sizeof(unsigned char));
    memcpy(output->buffer, input->buffer, output->width * output->height *3* sizeof(unsigned char)); //we want intput of all this to becopiedtobuffe
    for(int i=0; i < output->height; i++){ //added height instead of original width
        int index = (i*output->width+i)*3;
        output->buffer[index] = 255;
        //printf("%d\n", index);
        output->buffer[index+1] = 255;
        output->buffer[index+2] = 0;
    }
    return output;
}

int main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write */
    Image *img = ReadImage(argv[1]);    
    img = YellowDiagonal(img);
    WriteImage(img, argv[2]);
}

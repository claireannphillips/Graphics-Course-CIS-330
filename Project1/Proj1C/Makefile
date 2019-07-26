CC=gcc
CFLAG=-g -Wall -c -I./include
SOURCES=exp330.c tan330.c log330.c sin330.c cos330.c arctan330.c arccos330.c arcsin330.c 
#add all the .c files we have. new 3 ones too 
OBJECTS=$(SOURCES:%.c=bin/%.o)

all: bin/cli

bin/cli: cli/cli.c lib/libmath330.a include
	gcc -o bin/cli cli/cli.c -Iinclude -Llib -lmath330 -lm

#to build cli executable it needs the cli.c, libmath 330, and include directory 
#Sees cli exsists, check. Then looks for math330.a and goes to command below if it does not find lib/libmath330.a
#if we dont have include will look for a rule for include which is below
#-o for executable. -c to make into an object file. Binary is executable so -o

	 
#depends on files that live in 3 different palces so 3 different c to object files. 
bin/%.o: exp/%.c bin
	${CC} ${CFLAG} -o $@ $<

bin/%.o: trig/%.c bin
	${CC} ${CFLAG} -o $@ $<

bin/%.o: cli/%.c bin
	${CC} ${CFLAG} -o $@ $<

include:
	mkdir include
	cp *.h include

bin:
	mkdir bin

lib:
	mkdir lib

#ad all the files
lib/libmath330.a: lib include $(OBJECTS) 
	ar rcs libmath330.a $(OBJECTS)  
	mv libmath330.a lib
	rm $(OBJECTS)

#after dependency on objects can make lib dpeend on trig.a
#gcc linker is expecting libtrig.a when we say -ltrig
#bin as you create binary files in the future this is where you store them.Binary is executable that is not a script.

#Have the sources include the new 3 ones we made. 
#I where to find header files. -L path to find libraries -l exact library from that path 
#Have lib depend on something else like slide "Makefile example: multiplier lib" and the slide below.  

clean:
	rm -rf bin include lib

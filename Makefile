CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_MY_MAT=my_mat.o
FLAGS=-g -Wall

all: connections lib_mat
connections: $(OBJECT_MAIN) lib_mat
	$(CC) $(FLAGS) -o connections $(OBJECT_MAIN) lib_mat.a 
lib_mat: lib_mat.a
lib_mat.a: $(OBJECT_MY_MAT) 
	$(AR) -rcs lib_mat.a $(OBJECT_MY_MAT) 
main.o: main.c my_mat.h  
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c  
	$(CC) $(FLAGS) -c my_mat.c 

.PHONY: all clean

clean:
	rm -f *.o *.a connections 
#ifndef INCLUDED_HELPER
#define INCLUDED_HELPER

//PRE: flag indiciates whether input is a file name or an int
//POST: RV = a pointer to an array allocated on the heap
//that was contructed by the  the input type based on the
//flag.
//      numElements = input iff flag was 1; else numElements
//equals the number of elements read in from the file input
//stream.
int * getSequence(bool flag, char * input, int & numElements);

//PRE: readArray is a pointer to an array of characters
//POST: RV = a pointer to a copy of that array allocated on
//the heap.
int * copyArray(int * readArray, int numElements);

//PRE: anArray points to a int array with length numElements
//POST: prints the array to the OS stream.
void printArray(int * anArray, int numElements);

//PRE: input is a character array with no white space and
//     has a EOS character at the end.
//POST: Converts character array to its base 10 integer equivalent
int convertToInt(char input[]);

#endif

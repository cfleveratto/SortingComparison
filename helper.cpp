#include "helper.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>     // header file to use the functions
			// random() and srandom() 
#include <time.h>       // header file to use the function time()


using namespace std;

//PRE: flag indiciates whether input is a file name or an
//int. if flag = 1 then  input is an integer; else it is a
//file name.
//POST: RV = a pointer to an array allocated on the heap
//that was contructed by the  the input type based on the
//flag.
//      numElements = input iff flag was 1; else numElements
//equals the number of elements read in from the file input
//stream.
int * getSequence(bool flag, char * input, int & numElements) {
  int * newArray; //this will hold generated sequence 
  if (flag) {
    time_t tempTime;
    srandom(time(&tempTime)); //seeds different number based
			      //on RV of time.
    numElements = convertToInt(input);
    int * newArray = new int[numElements];
    for (int index = 0; (index < numElements); index++) {
      newArray[index] = (int)random();
      cout << newArray[index] << endl;
    }
    printArray(newArray, numElements);
  }
  return(newArray);
}

//PRE: readArray is a pointer to an array of integers with
//length numElements
//POST: RV = a pointer to a copy of that array allocated on
//the heap.
int * copyArray(int * readArray, int numElements) {
  int * newArray = new int[numElements];
  for (int index = 0; (index < numElements); index++) {
    newArray[index] = readArray[index];
  }
  return (newArray);
}

//PRE: anArray points to a int array with length numElements
//POST: prints the array to the OS stream.
void printArray(int * anArray, int numElements) {
  for (int index = 0; (index < numElements); index++) {
    cout << anArray[index] << endl;
  }
}

#define EOS '\0'
#define ZERO '0'

//PRE: input is a character array with no white space and
//     has a EOS character at the end.
//POST: Converts character array to its base 10 integer equivalent
int convertToInt(char input[]) {
  int index = 0;
  int base10result = 0;
  while (input[index] != EOS) {
    base10result += int(input[index]) - int(ZERO);
    base10result *= 10;
    index++;
  }
  base10result /= 10; /*undoes last multiplication of
			base10result. */
  //ASSERT:
  return base10result;
}

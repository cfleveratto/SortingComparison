#include "BOTree.h"
#include "helper.h"
#include "sorts.h"
#include <iostream>
#include <sys/times.h>  // header file to use the function times()
#include <unistd.h>     // header file to use the function sysconf()
#include <stdlib.h>     // header file to use the functions
			// random() and srandom() 
#include <time.h>       // header file to use the function time()
using namespace std;

//PRE: Commandline contains a flag input followed by a file
//name or  integer depending on the flag
//POST:  Computes the running time for heap sort, bubble
//sort and tree Sort
int main (int argc, char * argv[]) {
  if (argc != 3) {
    cout << "Usage: ./CompareSorts 0 <input file>" << endl;
    cout << "       ./CompareSorts 1 <num>" << endl;
  }
  else {
    // ASSERT: argument 1 is a flag. A value of 0 indicates that the
    // program is to be run on fixed input, and that the input
    // (sequence of integers) is in the file whose name is specified
    // as argument 2. The first number, n,  of the input file specifies how
    // many numbers are in the input sequence. Following the first
    // number there will be n numbers on the input file. Those n
    // numbers are to be treated as the sequence of numbers to be sorted.
    // If the flag is 1, this indicates that the program is to be run
    // on a random sequence of numbers and argument 2 specifies the
    // size, n, of the random sequence of numbers. Each number in the
    // random sequence should be generated in the range 0 through
    // 100000.
    bool generateSequence;
    if (convertToInt(argv[1]) == 1)
      generateSequence = true;
    else
      generateSequence = false;
    
    cout << generateSequence;
    int * sequence;     // the sequence of numbers to be sorted.
    int * sequence1;    // a copy of the sequence of numbers to be
			// sorted - to be used with heapsort 
    int * sequence2;    // another copy of the sequence of numbers to be
			// sorted - to be used with BOTree sort
    int numElements;    // the number of elements in the sequence of
			// numbers to be sorted.
    cout << "entering get sequence\n";
    sequence = getSequence (generateSequence, argv[2], numElements);
    cout << "exiting get sequence\n";
    // ASSERT: numElements = n sequence is an array of n
    // integers. Heap space for n integers is allocated for sequence.
    //sequence1 = copyArray (sequence, numElements);
    //sequence2 = copyArray (sequence, numElements);
    // ASSERT: sequence1 and sequence2 are copies of sequence.
    //  Heap space for n integers is allocated for sequence1 and
    //  n integers for sequence2.
    printArray(sequence, numElements);
    //printArray(sequence1, numElements);
    //printArray(sequence2, numElements);
    // double bubbleTime; // time in seconds to bubble sort sequence
    // double heapTime;   // time in seconds to heapsort sequence1
    // double BOTreeTime; // time in seconds to BOTree sort sequence2

    // struct tms timeStructure; // times() returns the number of clock
    // 			      // ticks that have elapsed since some
    // 			      // arbitrary time in the past. It expects
    // 			      // a pointer to a variable of type struct
    // 			      // tms.
    // long long int ticksPerSecond = sysconf(_SC_CLK_TCK);
    // cout << "Sorting a sequence of " << numElements << " integers." << endl;
    // cout << "======================" << endl;
    // time_t startTime = times(&timeStructure); //will get
    // 					      //starting
    // 					      //time of
    // 					      //bubble sort
    // bubbleSort (sequence, numElements);
    // // sequence now contains the initial sequence elements sorted in
    // // ascending order.
    // time_T endTime = times(&timeStructure); //gets the
    // 					    //ending time of
    // 					    //bubbleSort
    // bubbleTime = (double) (endTime - startTime) /  (double) ticksPerSecond;

    // cout << "Bubble sort time = " << bubbleTime << " seconds." << endl;
    // if (!generateSequence) {
    //   printArray (sequence, numElements);
    // }

    // cout << "======================" << endl;

    // startTime = times(&timeStructure); //will hold start
    // 				       //time of heapSort
    // heapSort (sequence1, numElements);
    // // sequence1 now contains the initial sequence1 elements sorted in
    // // ascending order.
    // endTime = times(&timeStructure); //will hold the end
    // 				     //time of heapSort
    // heapTime = (double) (endTime - startTime) / (double) ticksPerSecond;
                 
    // cout << "Heap sort time = " << heapTime << " seconds." << endl;
    // if (!generateSequence) {
    //   printArray (sequence1, numElements);
    // }

    // cout << "======================" << endl;
    
    // BOTree<int> tree; // tree is an empty balanced, ordered binary
    // 		      // tree. 

    // startTime = times(&timeStructure); //will hold start
    // 				       //time of treesort
    // makeTree (tree, sequence2, numElements);
    // // ASSERT: tree is a balanced ordered binary tree containing the
    // // integers from the sequence.
    // inOrderFromTree (tree, sequence2, numElements);
    // // ASSERT: sequence2 contains the elements from tree traversed
    // // using in-order traversal, and thus is sorted.
    // endTime = times(&timeStructure); //will hold the endtime
    // 				     //of tree sort.
    
    // BOTreeTime = (double) (endTime - startTime) / (double) ticksPerSecond;
    // cout << "BOTree sort time = " << BOTreeTime << " seconds." << endl;
    // if (!generateSequence) {
    //   printArray (sequence2, numElements);
    // }

    //delete [] sequence;
    //delete [] sequence1;
    //delete [] sequence2;
    //This deletes the int array allocated on the heap.

  }
  return (0);
}


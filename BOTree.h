#ifndef INCLUDED_BOTREE
#define INCLUDED_BOTREE

#include <iostream>
#include "BONode.h"

using namespace std;

template <class T>
class BOTree {
  //CLASS INVARIENT (CI): This object is an ordered binary
  //tree, and this object satisfies the property of a
  //balanced tree.
  
 private:
  BONode <T> * root; //Pointer to the BONode that is the
		     //root of the tree. 
  int numElements; //number of elements in the tree.

 public:

  BOTree<T> () {
    root = NULL;
    numElements = 0;
  };

  //PRE: This object is defined and has a satisfied CI.
  //POST: deletes all the BONode objects off the heap.
  ~BOTree<T> () {
    delete root;
  };

  //PRE: newData is of type T
  //POST: constructs a BONode for new data and places it in
  //this object.
  //      checks to see this object is balanced and if not
  //rotates it appropiately.
  insert (const T & newData) {
    //BONode<T> *

  };
};

#endif

  
  

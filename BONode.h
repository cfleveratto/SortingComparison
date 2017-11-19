#ifndef INCLUDED_BONODE
#define INCLUDED_BONODE

template <class T>
class BONode {
  //Class Invarient(CI): This object contains T data and has
  //a height and balance order 

  //parent points to the previous Node that this node is a
  //child to. 
  //left and right point to another BONode object with T
  //data where left < data and right >= data.

 private:
  T data; //contains data
  BONode<T> * parent; // will hold a pointer to its parent.
  BONode<T> * left; //Pointer to left child
  BONode<T> * right; //Pointer to right child
  int height; //will hold the computed height of this node
  int balance; //will hold the computed balance of this node
	       //which is the height of the left child minus
	       //the height of the right child.

 public:

  //PRE: element is of type T.
  //POST: This object is defined and has a satisfied CI.
  BONode<T> (T element) {
    data = element;
    parent = NULL;
    left = NULL;
    right = NULL;
    height = 1;
    balance = 0;
  };

  // ===================================
  //               ACCESSORS
  // ===================================

  //returns the height of this node
  int getheight() const {
    return(height);
  };

  //return the balance of this node
  int getbalance() const {
    return(balance);
  };
    
  //Returns the data this Node contains
  T getData() const{
    return(data);
  };

  //Returns what parent points to.
  BONode<T> * getParent() const {
    return(parent);
  };
  
  //Returns what left points to.
  BONode<T> * getLeft() const {
    return(left);
  };

  //Returns what right points to.
  BONode<T> * getRight() const {
    return(right);
  };

  // ===================================
  //              MODIFIER
  // ===================================

  //PRE: points to a defined BONode data object with a
  //satisfied CI.
  //POST: this node has is a child to a parent Node which
  //parent points to.
  void setParent(BONode<T> * nodeParent) {
    parent = nodeParent;
  };

  //PRE:
  //POST:
  void setLeftChild(BONode<T> * leftChild) {
    left = leftChild;
  };

  //PRE:
  //POST:
  void setRightChild(BONode<T> * rightChild) {
    right = rightChild;
  };
  
  // PRE: This object satisfies the CI.
  // POST: All dynamic memory allocated for this object (except any
  //         data allocated for T objects) is deallocated.
  ~BONode<T>() {
    if (left != NULL) 
      delete left;
    if (right != NULL)
      delete right;
  };
  
};

#endif

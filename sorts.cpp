void swap (int & num1, int & num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

void bubbleSort (int List[], int numElements) {
  bool madeSwap;
  do {
    madeSwap = false;
    for (int index = 0; index < (numElements-1); index++) {
      if (List[index] > List[index+1]) {
	swap (List[index], List[index+1]);
	madeSwap = true;
      }
    }
  }
  while (madeSwap);
}

void heapify (int heap[], int atIndex) {
  bool done = false;
  while ((!done) && (atIndex > 0)) {
    int parent;
    if (atIndex % 2 == 0) {
      parent = (atIndex - 2)/2;
    }
    else {
      parent = (atIndex - 1)/2;
    }
    if (heap[atIndex] < heap[parent]) {
      swap (heap[atIndex], heap[parent]);
      atIndex = parent;
    }
    else {
      done = true;
    }
  }
}

void reheapify (int heap[], int heapELements, int atIndex) {
  bool done = false;
  while (!done) {
    int leftChildIndex = 2 * atIndex + 1;
    if (leftChildIndex < heapELements) {
      int rightChildIndex = 2 * atIndex + 2;
      int childrenMin = heap[leftChildIndex];
      int minChildIndex = leftChildIndex;
      if ((rightChildIndex < heapELements)
	  && (heap[rightChildIndex] < childrenMin)) {
	childrenMin = heap[rightChildIndex];
	minChildIndex = rightChildIndex;
      }
      if (heap[atIndex] >= heap[minChildIndex]) {
	swap (heap[atIndex], heap[minChildIndex]);
	atIndex = minChildIndex;
      }
      else {
	done = true;
      }
    }
    else {
      done = true;
    }
  }
}

void heapSort (int List[], int numElements) {
  int * heap = new int[numElements];
  int heapELements = 0;
  for (int index = 0; index < numElements; index++) {
    heap[heapELements] = List[index];
    heapELements++;
    heapify (heap, heapELements-1);
  }
  for (int index = 0; index < numElements; index++) {
    List[index] = heap[0];
    swap (heap[0], heap[heapELements-1]);
    heapELements--;
    reheapify (heap, heapELements, 0);
  }
}

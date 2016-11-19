//
//  BinaryHeap.cpp
//  Project 1
//
//  Implemented with Data Structures & Algorithms in C++ Textbook.
//  Copyright © 2014, 2006, 1999 Pearson Education, Inc., publishing as Addison-Wesley. All rights reserved.
//

#include <iostream>
#include "BinaryHeap.h"

using namespace std;

/* Explicitly-Defined Default Constructor */

template<typename T>
BinaryHeap<T>::BinaryHeap() : currentSize_(0) {}

/* Explicitly-Defined Constructor */

template<typename T>
BinaryHeap<T>::BinaryHeap(const vector<T>& initItems) : currentSize_(initItems.size()), array_(currentSize_ + 10) {
  for(int i = 0; i < currentSize_; ++i) {
  	array_[i + 1] = initItems[i];
  }

  buildHeap();
}

/* Heap Modification Functions */

//  Insert item 'initNewItem.'
//  Duplicates are permitted. 

template<typename T>
void BinaryHeap<T>::insert(const T& initNewItem) {
  if(currentSize_ == array_.size() - 1)
  	array_.resize(array_.size() * 2);
 
  // Percolate Up.
  int hole = ++currentSize_;
  T copy = initNewItem;

  array_[0] = move(copy);
  for(; initNewItem < array_[hole / 2]; hole /= 2)
  	array_[hole] = move(array_[hole / 2 ]);
  array_[hole] = move(array_[0]);
}

//  Removes item at index 1 (minItem) of the heapArray.
//  Invokes exit() function if empty. 

template<typename T>
void BinaryHeap<T>::deleteMin() {
  if(isEmpty()) {
    cout << "Heap is empty.\n";
    throw -1;
  }

  array_[1] = move(array_[currentSize_--]);
  percolateDown(1);
}

//  Removes minItem, and stores it in initMinItem.
//  Invokes exit() function if empty.

template<typename T>
void BinaryHeap<T>::deleteMin(T& initMinItem) {
  if(isEmpty()) {
    cout << "Heap is empty.\n";
    throw -1;
  }

  initMinItem = move(array_[1]);
  array_[1] = move(array_[currentSize_--]);
  percolateDown(1);  
}

/* Convenience Functions */

template<typename T>
bool BinaryHeap<T>::isEmpty() const {
  return array_.empty();
}

template<typename T>
const T& BinaryHeap<T>::findMin() const {
  return array_[1]; 
}

template<typename T>
unsigned int BinaryHeap<T>::size() const {
  return currentSize_;
}

template<typename T>
const T& BinaryHeap<T>::at(unsigned int initIndexPos) const {
  if(isEmpty()) {
    cout << "Heap is empty.\n";
    throw -1;
  }

  else if(initIndexPos < 1 || initIndexPos > currentSize_) {
    cout << "Out of bounds: This index of Heap Array is empty.\n";
    throw -1;
  }

  return array_.at(initIndexPos);
}

template<typename T>
void BinaryHeap<T>::printHeap() const {
  if(!isEmpty()) {
    for(int i = 1; i <= currentSize_; ++i) {
      cout << array_.at(i) << " ";
    }
    cout << "\n";
  }
}

/* Private Helper Functions */

//  Internal Method to percolate down in the heap.
//  initHole is the index at which the percolating begins.

template<typename T>
void BinaryHeap<T>::percolateDown(int initHole) {
  int child;
  T tmp = move(array_[initHole]);

  for(; initHole * 2 <= currentSize_; initHole = child) {
    child = initHole * 2; 

    if(child != currentSize_ && array_[child + 1] < array_[child])
      ++child;

    if(array_[child] < tmp)
      array_[initHole] = move(array_[child]);

    else 
      break;
  }
  
  array_[initHole] = move(tmp);
}

//  Establish Heap Order property on an arbitrary 
//  arrangement of items. O(N) steps. 

template<typename T>
void BinaryHeap<T>::buildHeap() {
  for(int i = currentSize_ / 2; i > 0; --i)
  	percolateDown(i);
}

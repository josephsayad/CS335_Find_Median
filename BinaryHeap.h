//
//  BinaryHeap.h
//  Project 1
//
//  Implemented with Data Structures & Algorithms in C++ Textbook.
//  Copyright © 2014, 2006, 1999 Pearson Education, Inc., publishing as Addison-Wesley. All rights reserved.
//

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
using namespace std;

template<typename T>
class BinaryHeap {
  public:

    /* Explicitly-Defined Default Constructor */
    BinaryHeap();

    /* Explicitly-Defined Constructor */
    explicit BinaryHeap(const vector<T>& initItems);
    
    /* Heap Modification Functions */
    void insert(const T& initNewItem);
    void deleteMin();
    void deleteMin(T& initMinItem);
    
    /* Heap Sort Functionality: In-Place */
    void heapSort(const unsigned int indexOfMedian);
    void heapify(const unsigned int startIndex, unsigned int sizeOfHeap);

    /* Accessor Function */
    vector<int> getHeapArray();

    /* Convenience Functions */
    bool isEmpty() const;
    const T& findMin() const;
    const T& at(unsigned int initIndexPos) const;
    unsigned int size() const;
    void printHeap() const;

  private:
    
    /* Private Data Members */
    unsigned int currentSize_; //  Number of Elements in the array.
    vector<T> array_; //  Heap Array.

    /* Private Helper Functions */
    void percolateDown(int initHole);
    void buildHeap();
};

#endif 

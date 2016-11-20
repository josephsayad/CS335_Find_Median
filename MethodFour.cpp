//
//  MethodFour.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/19/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include "BinaryHeap.cpp"
#include "MethodFour.h"

using namespace std; 

int methodFour(BinaryHeap<int>& theHeap, const unsigned int& indexOfMedian) {
  theHeap.heapSort(indexOfMedian);
  return theHeap.findMin();
}
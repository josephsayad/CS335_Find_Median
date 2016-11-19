//
//  MethodThree.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/15/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <algorithm>

#include "MethodThree.h"
#include "MethodOne.h" //  For printVector() function

using namespace std;

int methodThree(vector<int>& theVector, const unsigned int& indexOfMedian) {
  return findMedianThree(theVector, indexOfMedian);
}

int findMedianThree(vector<int>& theVector, const unsigned int& indexOfMedian) {
  mergeSort(theVector.begin(), theVector.end());
  return theVector.at(indexOfMedian);
}

template<class Iter>
void mergeSort(Iter start, Iter end) {
  if (end - start > 1) {
    Iter middle = start + (end - start) / 2;
    mergeSort(start, middle);
    mergeSort(middle, end);
    std::inplace_merge(start, middle, end);
  }
}

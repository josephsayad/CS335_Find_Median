//
//  MethodThree.cpp
//  Project 1
//
//  Written out by Joseph Sayad on 11/15/16.
//  All rights reserved to: http://en.cppreference.com/w/cpp/algorithm/inplace_merge
//  mergeSort taken by verbatim. 

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
void mergeSort(Iter first, Iter last) {
  if (last - first > 1) {
    Iter middle = first + (last - first) / 2;
    mergeSort(first, middle);
    mergeSort(middle, last);
    std::inplace_merge(first, middle, last);
  }
}

//
//  MethodThree.cpp
//  Project 1
//
//  Written by Joseph Sayad on 11/15/16.
//  Rights reserved to [http://en.cppreference.com/w/cpp/algorithm/inplace_merge]

#include <iostream>
#include <algorithm>
#include "MethodThree.h"
#include "MethodOne.h" //  Convenience function: printVector()

using namespace std;

int methodThree(vector<int>& theVector, const unsigned int& indexOfMedian) {
  return findMedianThree(theVector, indexOfMedian);
}

int findMedianThree(vector<int>& theVector, const unsigned int& indexOfMedian) {
  mergeSort(theVector.begin(), theVector.end());
  return theVector.at(indexOfMedian);
}

/* In-Place Merge Sort: Copied Verbatim */

template<class Iter>
void mergeSort(Iter first, Iter last) {
  if (last - first > 1) {
    Iter middle = first + (last - first) / 2;
    mergeSort(first, middle);
    mergeSort(middle, last);
    std::inplace_merge(first, middle, last);
  }
}

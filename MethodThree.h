//
//  MethodThree.cpp
//  Project 1
//
//  Written by Joseph Sayad on 11/15/16.
//  Rights reserved to [http://en.cppreference.com/w/cpp/algorithm/inplace_merge]

#ifndef METHODTHREE_H
#define METHODTHREE_H

#include <vector>

using namespace std;

int methodThree(vector<int>& theVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: Returns the Median via in-place merge sort.

int findMedianThree(vector<int>& theVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: References the index of the median, and returns element
//  found in said position.

template<typename Iter>
void mergeSort(Iter first, Iter last);
//  Precondition: Templating for use of iterators. 
//  Postcondition: Sorts unsorted list of integers via in-place merge sort.

/* Convenience Function: Implemented in MethodOne.cpp */

void printVector(vector<int>& theVector);

#endif

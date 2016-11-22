//
//  MethodThree.cpp
//  Project 1
//
//  Written out by Joseph Sayad on 11/15/16.
//  All rights reserved to: http://en.cppreference.com/w/cpp/algorithm/inplace_merge
//  mergeSort taken by verbatim. 

#ifndef METHODTHREE_H
#define METHODTHREE_H

#include <vector>

using namespace std;

int methodThree(vector<int>& theVector, const unsigned int& indexOfMedian);

int findMedianThree(vector<int>& theVector, const unsigned int& indexOfMedian);

template<typename Iter>
void mergeSort(Iter first, Iter last);

/* Convenience Function: Implemented in MethodOne.cpp */
void printVector(vector<int>& theVector);

#endif

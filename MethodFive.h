//
//  MethodFive.h
//  Project 1
//
//  Implemented with Data Structures & Algorithms in C++ Textbook.
//  Copyright © 2014, 2006, 1999 Pearson Education, Inc., publishing as Addison-Wesley. All rights reserved.

#ifndef METHODFIVE_H
#define METHODFIVE_H

#include <vector>
#include "MethodOne.h" //  Convenience function: printVector()

using namespace std;

int methodFive(vector<int>& theVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: References the index of the median, and returns the 
//  Median via Quick Select.

void quickSelect(vector<int>& theVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int - position kth 
//  smallest element - via: pass-by-reference.
//  Postcondition: Invokes recursive helper.

void quickSelectHelper(vector<int>& theVector, int left, int right, int k);
//  Precondition: Accepts objects of type vector, and 3 ints - position kth via: 
//  pass-by-reference. Left, and right signify positions within the sub-array. K
//  signifies the kth smallest element - which is used to leverage the recursive 
//  step. 
//  Postcondition: Quick sort relevant areas of array-based data structure, and 
//  finishes sorting via std::sort.

const int& medianOfThree(vector<int>& theVector, int left, int right);
//  Precondition: Templating for use of iterators. 
//  Postcondition: Returns median-of-three.

/* Convenience Function */

void printVector(vector<int>& theVector);

#endif

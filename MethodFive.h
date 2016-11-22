//
//  MethodFive.h
//  Project 1
//
//  Implemented with Data Structures & Algorithms in C++ Textbook.
//  Copyright © 2014, 2006, 1999 Pearson Education, Inc., publishing as Addison-Wesley. All rights reserved.
//  Code has been modified.

#ifndef METHODFIVE_H
#define METHODFIVE_H

#include <vector>
#include "MethodOne.h" // printVector()

using namespace std;

int methodFive(vector<int>& theVector, const unsigned int& indexOfMedian);
void quickSelect(vector<int>& theVector, const unsigned int& indexOfMedian);
void quickSelectHelper(vector<int>& theVector, int left, int right, int k);
const int& medianOfThree(vector<int>& theVector, int left, int right);

/* Convenience Functions */

unsigned int getMiddleIndexOfSubArray(vector<int>& theVector);
void insertionSort(vector<int>& theVector, int left, int right);
void insert(vector<int>& theVector, int rightIndex, int value);
void printVector(vector<int>& theVector);

#endif

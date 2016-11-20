//
//  MethodOne.h
//  Project 1
//
//  Created by Joseph Sayad on 11/15/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODONE_H
#define METHODONE_H

#include <vector>

using namespace std; 

int methodOne(vector<int>& theVector, const unsigned int& indexOfMedian);
int findMedianOne(vector<int>& theVector, const unsigned int& indexOfMedian);
void selectionSort(vector<int>& theVector, const unsigned int& indexOfMedian);
unsigned int indexOfMinimum(vector<int>& theVector, unsigned int startIndex);
void swap(vector<int>& theVector, unsigned int startIndex, unsigned int minIndex);


/* Convenience Function */
void printVector(vector<int>& theVector);

#endif

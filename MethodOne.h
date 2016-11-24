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
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: Returns the Median via selection sort. A SIZE_LIMIT is 
//  defined at input size 1000000.

int findMedianOne(vector<int>& theVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: Invokes a selection sort, references the index of the median,
//  and and returns element found in said position.

void selectionSort(vector<int>& theVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: Sorts unsorted list of integers via selection sort.

unsigned int indexOfMinimum(vector<int>& theVector, unsigned int startIndex);
//  Precondition: Accepts objects of type vector, and unsigned int via: 
//  pass-by-reference. These value signifies the start index.
//  Postcondition: Returns index of the minimum element in the array-based 
//  data structure, which is of value unsigned int.

void swap(vector<int>& theVector, unsigned int startIndex, unsigned int minIndex);
//  Precondition: Accepts objects of type vector, and 2 unsigned ints via: 
//  pass-by-reference. These values signify the start, and min index. 
//  Postcondition: Swaps the values at index [start], and [min] if necessary.

/* Convenience Function */

void printVector(vector<int>& theVector);

#endif

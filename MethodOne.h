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
int findMedian(vector<int>& theVector, const unsigned int& indexOfMedian);
void selectionSort(vector<int>& theVector, const unsigned int& indexOfMedian);
unsigned int indexOfMinimum(vector<int>& theVector, unsigned int startIndex);
void swap(vector<int>& theVector, unsigned int startIndex, unsigned int minIndex);


/* Convenience Function */
void printVector(vector<int>& vector);

#endif


/*  Pseudo-Code For Method ***********************
 *  Selection Sort: Takes (N^2)/2 steps, or O(N^2)
 *  **********************************************
 *  1: if (v.size() > 50,000) then: "input is too big for selection sort."
 *  2: else: continue with step 3.
 *  3: selectionSort() to element at index n/2 
 *  4: return element at(n/2)
 */

//
//  MethodFive.cpp
//  Project 1
//
//  Implemented with Data Structures & Algorithms in C++ Textbook.
//  Copyright © 2014, 2006, 1999 Pearson Education, Inc., publishing as Addison-Wesley. All rights reserved.

#include <iostream>
#include <algorithm>
#include "MethodFive.h"

using namespace std;

int methodFive(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelect(theVector, indexOfMedian); //  the median will be our kth smallest element.
  return theVector.at(indexOfMedian);
}

void quickSelect(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelectHelper(theVector, 0, theVector.size() - 1, indexOfMedian);
}

/* Quick Select And Median Of Three: Copied Verbatim
 *
 * Modifications Have been Made.
 * 1: Recursive Base-Case.
 * 2: Use of std::sort rather than insertion.
 *
 * Internal quick select method makes recursive calls. 
 * Uses median-of-three partitioning and a cutoff of 24.
 * theVector is an array-based data structure of integer items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */ 

void quickSelectHelper(vector<int>& theVector, int left, int right, int k) {
  if(left + 24 <= right) {
    const int& pivot = medianOfThree(theVector, left, right);
    
    //  Begin partitioning. 
    int i = left, j = right - 1;

    for(; ;) {
      while(theVector.at(++i) < pivot) {}
      while(pivot < theVector.at(--j)) {} 
      if(i < j) {
        swap(theVector.at(i), theVector.at(j));
      }
      else {
        break;
      }
    }

    swap(theVector.at(i), theVector.at(right - 1)); // Restore pivot
    
    /* Recursive Call: Dependent on the kth smallest element. */

    if(k <= i)
      quickSelectHelper(theVector, left, i - 1, k);
    else if(k > i + 1)
      quickSelectHelper(theVector, i + 1, right, k);
  } 

  else {
    sort(theVector.begin(), theVector.end());
  } 
}

const int& medianOfThree(vector<int>& theVector, int left, int right) {
  int center = (left + right) / 2; 

  if(theVector.at(center) < theVector.at(left)) {
    swap(theVector.at(left), theVector.at(center));
  }   
  if(theVector.at(right) < theVector.at(left)) {
    swap(theVector.at(left), theVector.at(right));
  }
  if(theVector.at(right) < theVector.at(center)) {
    swap(theVector.at(center), theVector.at(right));
  }

  // Place pivot at position right - 1. 
  swap(theVector.at(center), theVector.at(right - 1));
  return theVector.at(right - 1);
}

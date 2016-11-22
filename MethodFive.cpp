//
//  MethodFive.cpp
//  Project 1
//
//  Implemented with Data Structures & Algorithms in C++ Textbook.
//  Copyright © 2014, 2006, 1999 Pearson Education, Inc., publishing as Addison-Wesley. All rights reserved.
//  Code has been modified.

#include <iostream>
#include <algorithm>
#include "MethodFive.h"

using namespace std;

int methodFive(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelect(theVector, indexOfMedian);
  return theVector.at(indexOfMedian);
}

void quickSelect(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelectHelper(theVector, 0, theVector.size() - 1, indexOfMedian);
}

void quickSelectHelper(vector<int>& theVector, int left, int right, int k) {
  if(left + 10 <= right) {
    const int& pivot = medianOfThree(theVector, left, right);
    
    //  Partition: 
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

    swap(theVector.at(i), theVector.at(right - 1));
    
    if(k <= i)
      quickSelectHelper(theVector, left, i - 1, k);
    else if(k > i + 1)
      quickSelectHelper(theVector, i + 1, right, k);
  } 

  else {
    // insertionSort(theVector, 0, theVector.size() - 1); IF used: hangs for input 8, and 9...
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

  swap(theVector.at(center), theVector.at(right - 1));
  return theVector.at(right - 1);
}

unsigned int getMiddleIndexOfSubArray(vector<int>& theVector) {
  unsigned int mid;

  if(theVector.size() % 2 != 0) { mid = theVector.size() / 2; } 
  else { mid = (theVector.size() / 2) - 1; }

  return mid;
}

void insertionSort(vector<int>& theVector, int left, int right) {
  for(int i = left; i < theVector.size(); i++) {
    insert(theVector, i - 1, theVector.at(i));
  }
}

void insert(vector<int>& theVector, int rightIndex, int valueToCompare) {
  for(int j = rightIndex; j >= 0 && theVector.at(j) > valueToCompare; j--) {
    int temp = theVector.at(j + 1);
    theVector.at(j + 1) = theVector.at(j);
    theVector.at(j) = temp;
  } 
}

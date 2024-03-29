//
//  MethodOne.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/15/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include "MethodOne.h"

using namespace std;


const unsigned int SIZE_LIMIT = 50000;

int methodOne(vector<int>& theVector, const unsigned int& indexOfMedian) {
  if(theVector.size() > SIZE_LIMIT) {
    return -1; //  -1 indicates SIZE_LIMIT has been reached. 
  }

  else {
    return findMedianOne(theVector, indexOfMedian);
  }
}

int findMedianOne(vector<int>& theVector, const unsigned int& indexOfMedian) {
  selectionSort(theVector, indexOfMedian);  
  return theVector.at(indexOfMedian);
}

void selectionSort(vector<int>& theVector, const unsigned int& indexOfMedian) {
  int minIndex; 

  //  Selection Sort runs to the index of the median: 
  //  half the input size. 
  for(unsigned int i = 0; i <= indexOfMedian; i++) {
    minIndex = indexOfMinimum(theVector, i);
    swap(theVector, i, minIndex);
  }
}

unsigned int indexOfMinimum(vector<int>& theVector, unsigned int startIndex) {
  unsigned int index = startIndex;

  for(unsigned int i = startIndex + 1; i < theVector.size(); i++) {
  	if(theVector.at(i) < theVector.at(index)) {
  	  index = i;
  	}
  }

  return index;
}

void swap(vector<int>& theVector, unsigned int startIndex, unsigned int minIndex) {
  int temp = theVector.at(startIndex);
  theVector.at(startIndex) = theVector.at(minIndex);
  theVector.at(minIndex) = temp;
}

/* Convenience Function */

void printVector(vector<int>& theVector) {
  for(auto i : theVector) {
    cout << i << " ";
  }
  
  cout << "\n";
}

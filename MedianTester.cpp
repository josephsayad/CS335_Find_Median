//
//  MedianTester.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/12/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "MedianTester.h"
#include "MethodOne.h" //  printVector() function

using namespace std;

void sortVector(vector<int>& unsortedVector) {
  sort(unsortedVector.begin(), unsortedVector.end());
}

int findMedianTwo(const vector<int>& sortedVector, const unsigned int& indexOfMedian) {
  return sortedVector.at(indexOfMedian);
}

int runMedianTest(vector<int>& vectorToBeTested, const unsigned int& indexOfMedian) {
  //  The std::sort is an algorithm that use the operator< 
  //  by default. 
  sortVector(vectorToBeTested);
  return findMedianTwo(vectorToBeTested, indexOfMedian); 
}

//
//  MedianTester.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/12/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

#include "MedianTester.h"

using namespace std;

void sortVector(vector<int>& unsortedVector) {
  sort(unsortedVector.begin(), unsortedVector.end());
}

int findMedian(const vector<int>& sortedVector) {
  if(sortedVector.size() % 2 != 0) {
    return sortedVector.at(floor(sortedVector.size() / 2.0));
  }
  else {
    int index = sortedVector.size() / 2.0;
    return sortedVector.at(index - 1);
  }
}

int runMedianTest(vector<int>& vectorToBeTested) {
  sortVector(vectorToBeTested);
  return findMedian(vectorToBeTested); 
}

/*  The std::sort is an algorithm that use the operator< 
 *  by default. 
 */
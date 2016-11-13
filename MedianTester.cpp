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

//  The std::sort algorithm use the < operator by default. 

void sortVector(vector<int>& unsortedVector) {
  sort(unsortedVector.begin(), unsortedVector.end());
}

int findMedian(vector<int>& sortedVector) {
  if(sortedVector.size() % 2 != 0) {
    return sortedVector.at(floor(sortedVector.size() / 2.0));
  }
  else {
    int index = sortedVector.size() / 2.0;
    return ((sortedVector.at(index) + sortedVector.at(index - 1)) / 2);
  }
}

int runMedianTest(vector<int>& vectorToBeTested) {
  sortVector(vectorToBeTested);
  return findMedian(vectorToBeTested); 
}

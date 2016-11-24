//
//  MedianTester.h
//  Project 1
//
//  Created by Joseph Sayad on 11/12/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef MEDIANTESTER_H
#define MEDIANTESTER_H

#include <vector>

using namespace std;

int runMedianTest(vector<int>& unsortedVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: Returns the Median via Standard STL Sort. 

void sortVector(vector<int>& unsortedVector);
//  Precondition: Accepts objects of type vector. 
//  Postcondition: Invokes Standard STL Sort with use of iterators. 

int findMedianTwo(const vector<int>& sortedVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: References the index of the median, and returns element
//  found in said position.

#endif

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
void sortVector(vector<int>& unsortedVector); //  O(Nlog(N)) steps
int findMedianTwo(const vector<int>& sortedVector, const unsigned int& indexOfMedian); //  O(N) steps

#endif 
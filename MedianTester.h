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

int runMedianTest(vector<int>& unsortedVector);
void sortVector(vector<int>& unsortedVector); //  O(Nlog(N)) steps
int findMedian(const vector<int>& sortedVector); //  O(N) steps

#endif 
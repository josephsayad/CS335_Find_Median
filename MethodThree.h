//
//  MethodThree.h
//  Project 1
//
//  Created by Joseph Sayad on 11/15/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODTHREE_H
#define METHODTHREE_H

#include <vector>
using namespace std;

int methodThree(vector<int>& theVector, const unsigned int& indexOfMedian);
int findMedianThree(vector<int>& theVector, const unsigned int& indexOfMedian);

template<typename Iter>
void mergeSort(Iter start, Iter end);

/* Convenience Function */
void printVector(vector<int>& theVector);

#endif

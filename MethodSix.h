//
//  MethodSix.h
//  Project 1
//
//  Created by Joseph Sayad on 11/20/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODSIX_H
#define METHODSIX_H

#include <vector>
using namespace std;

int methodSix(vector<int>& theVector, const unsigned int& indexOfMedian);
int medianOfMedians(vector<int>& theVector); 

void quickSelectMethodSix(vector<int>& theVector, const unsigned int& indexOfMedian);
void quickSelectMethodSixHelper(vector<int>& theVector, int left, int right, int k);

template<typename Iterator>
int medianOfFive(Iterator first, Iterator last); 

template<typename Iterator>
int medianOfThree(Iterator first, Iterator middle, Iterator last);

template<typename Iterator>
int medianOfFour(Iterator first, Iterator firstMiddle, Iterator secondMiddle, Iterator last);

#endif 
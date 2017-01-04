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
//  Precondition: Accepts objects of type vector, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: References the index of the median, and returns the 
//  Median via Quick Select.

int medianOfMedians(vector<int>& theVector);
//  Precondition: Accepts objects of type vector.
//  Postcondition: A recursive function that finds the median-of-medians: 
//  which is to be used as the pivot for Quick Select.

void quickSelectMethodSix(vector<int>& theVector, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type vector, and const unsigned int - position kth 
//  smallest element - via: pass-by-reference.
//  Postcondition: Invokes recursive helper.

void quickSelectMethodSixHelper(vector<int>& theVector, int left, int right, int k);
//  Precondition: Accepts objects of type vector, and 3 ints - position kth via: 
//  pass-by-reference. Left, and right signify positions within the sub-array. K
//  signifies the kth smallest element - which is used to leverage the recursive 
//  step. 
//  Postcondition: Quick sort relevant areas of array-based data structure, and 
//  finishes sorting via std::sort.

template<typename Iterator>
int medianOfFive(Iterator first, Iterator last); 
//  Precondition: Templating for use of iterators. 
//  Postcondition: Returns median-of-five.

template<typename Iterator>
int medianOfThree(Iterator first, Iterator middle, Iterator last);
//  Precondition: Templating for use of iterators. 
//  Postcondition: Returns median-of-three.

template<typename Iterator>
int medianOfFour(Iterator first, Iterator firstMiddle, Iterator secondMiddle, Iterator last);
//  Precondition: Templating for use of iterators. 
//  Postcondition: Returns median-of-four.

#endif 
//
//  MethodFour.h
//  Project 1
//
//  Created by Joseph Sayad on 11/19/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODFOUR_H
#define METHODFOUR_H

#include <vector>
#include "BinaryHeap.h"

using namespace std;

int methodFour(BinaryHeap<int>& theHeap, const unsigned int& indexOfMedian);
//  Precondition: Accepts objects of type BinaryHeap, and const unsigned int 
//  via: pass-by-reference.
//  Postcondition: Returns the Median via HeapSort. HeapSort is a member function
//  of the BinaryHeap class.

#endif

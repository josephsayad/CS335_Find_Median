//
//  MethodSix.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/21/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.

#include <iostream>
#include <algorithm>
#include <cmath>
#include "MethodSix.h"

int methodSix(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelectMethodSix(theVector, indexOfMedian); //  the median will be our kth smallest element.
  return theVector.at(indexOfMedian);
}

int medianOfMedians(vector<int>& theVector) {
  vector<int> storageForMedians;
  vector<int>::iterator it;

  int sizeOfVector = theVector.size();
  int elementsLeft = sizeOfVector; //  Keep Count of Elements to process.
  int elementCount = 0; //  Keep Count of Elements processed.
 
  if(theVector.size() <= 24) { //  If Base-case [at 24 elements or less]: 
    sort(theVector.begin(), theVector.end());
    
    int pivotIndex; 

    if(theVector.size() % 2 != 0) { pivotIndex = theVector.size() / 2; } //  Odd: Middle element.
    else { pivotIndex = (theVector.size() / 2) - 1; } //  Even: Lower of two middle elements.
    
    return theVector.at(pivotIndex);
  }

  else { // Else base-case not hit: 

    for(it = theVector.begin(); it < theVector.end(); it+=5) {
      if(elementsLeft == 1 || elementsLeft == 2) { 
        // cout << "1, or 2 elements left! Do nothing.\n"; 
      }

      //  else if 3 elements left: take the median-of-three.
      else if(elementsLeft == 3) {
        storageForMedians.push_back(medianOfThree(it, it + 1, it + 2));
      }

      //  else if 4 elements left: take the median-of-four.
      else if(elementsLeft == 4) { 
        storageForMedians.push_back(medianOfFour(it, it + 1, it + 2, it + 3));
      }
    
      //  else 5 elements left: take the median-of-five.
      else {
        storageForMedians.push_back(medianOfFive(it, it + 4));
        elementCount += 5;
        elementsLeft -= 5;
      }
    }
    
    //  Recurse! 
    return medianOfMedians(storageForMedians);  
  }
} 

template<typename Iterator>
int medianOfFive(Iterator first, Iterator last) {
  vector<int>::iterator a = first;
  vector<int>::iterator b = first + 1;
  vector<int>::iterator c = first + 2;
  vector<int>::iterator d = first + 3;
  vector<int>::iterator e = first + 4;
  
  // Comparison 1. 
  if(*a < *b) {
    swap(*a, *b);
  }

  // Comparison 2.
  if(*c < *d) {
    swap(*c, *d);
  }

  // Comparison 3.
  if(*a < *c) {
    swap(*c, *e);

    // Comparison 4.
    if(*c < *d) {
      swap(*c, *d);
    }
  }
  else {
    swap(*a, *e);

    // Comparison 4.
    if(*a < *b) {
      swap(*a, *b);
    }
  }

  // Comparison 5.
  if(*a < *c) {
    swap(*a, *c);    
  }

  // Comparison 6: Take Largest of 3 Remaing elements.
  if(*b > *c && *b > *d) {
    return *b;
  }

  else if(*b < *c && *b < *d) {
    if(*c < *d) { return *d; }
    else { return *c; }
  } 

  else if(*b < *c &&  *b > *d) {
    return *c;
  }

  else {
    return *d;
  }

} 

template<typename Iterator>
int medianOfThree(Iterator first, Iterator middle, Iterator last) {
  // Comparison 1
  if(*first < *middle) {
    swap(*first, *middle);
  }

  // Comparison 2
  if(*middle < *last) {
    swap(*middle, *last);
  }

  // Comparison 3
  if(*first < *middle) {
    swap(*first, *middle);
  }

  return *middle;
}

template<typename Iterator>
int medianOfFour(Iterator first, Iterator firstMiddle, Iterator secondMiddle, Iterator last) {
  vector<int> v {*first, *firstMiddle, *secondMiddle, *last };
  sort(v.begin(), v.end());

  return v.at(1);
}

/* Quick Select: Copied Verbatim
 *
 * Modifications Have been Made.
 * 1: Recursive Base-Case.
 * 2: Use of std::sort rather than insertion.
 *
 * Internal quick select method makes recursive calls. 
 * Uses median-of-medians partitioning and a cutoff of 24.
 * theVector is an array-based data structure of integer items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */ 

void quickSelectMethodSix(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelectMethodSixHelper(theVector, 0, theVector.size() - 1, indexOfMedian);
}

void quickSelectMethodSixHelper(vector<int>& theVector, int left, int right, int k) {
  if(left + 24 <= right) {

    //  Update Vector.
    auto start = theVector.begin() + left;
    auto end = theVector.begin() + right;
    vector<int> vectorUpdate(start, end);
  
    //  Acquire Pivot via median-of-medians. 
    const int& pivot = medianOfMedians(vectorUpdate);

    for(unsigned int i = 0; i < theVector.size(); ++i) {
      if(theVector.at(i) == pivot) {
        swap(theVector.at(i), theVector.at(right));
      }
    }
    
    //  Begin partition. 
    int i = left, j = right - 1;

    for(; ;) {
      while(theVector.at(++i) < pivot) {}
      while(pivot < theVector.at(--j)) {} 
      if(i < j) {
        swap(theVector.at(i), theVector.at(j));
      }
      else {
        break;
      }
    }

    swap(theVector.at(i), theVector.at(right - 1)); //  Restore Pivot.
    
    /* Recursive Call: Dependent on the kth smallest element. */

    if(k <= i)
      quickSelectMethodSixHelper(theVector, left, i - 1, k);
    else if(k > i + 1)
      quickSelectMethodSixHelper(theVector, i + 1, right, k);
  } 

  else {
    sort(theVector.begin(), theVector.end());
  } 
}

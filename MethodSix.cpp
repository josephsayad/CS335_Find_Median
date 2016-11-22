#include <iostream>
#include <algorithm>
#include <cmath>
#include "MethodSix.h"

int methodSix(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelectMethodSix(theVector, indexOfMedian);
  return theVector.at(indexOfMedian);
}

int medianOfMedians(vector<int>& theVector) {
  vector<int> storageForMedians;
  vector<int>::iterator it;

  int sizeOfVector = theVector.size();
  int elementsLeft = sizeOfVector;
  int elementCount = 0;
 
  if(theVector.size() <= 24) {
    sort(theVector.begin(), theVector.end());
    
    int pivotIndex; 

    if(theVector.size() % 2 != 0) { pivotIndex = theVector.size() / 2; } //  Odd: Middle element.
    else { pivotIndex = (theVector.size() / 2) - 1; } //  Even: Lower of two middle elements.
    
    return theVector.at(pivotIndex);
  }

  else {
    for(it = theVector.begin(); it < theVector.end(); it+=5) {
      if(elementsLeft == 1 || elementsLeft == 2) { 
        // cout << "1 element left! Do nothing.\n"; 
      }

      else if(elementsLeft == 3) {
        storageForMedians.push_back(medianOfThree(it, it + 1, it + 2));
      }

      else if(elementsLeft == 4) {
        storageForMedians.push_back(medianOfFour(it, it + 1, it + 2, it + 3));
      }
    
      else {
        storageForMedians.push_back(medianOfFive(it, it + 4));
        elementCount += 5;
        elementsLeft -= 5;
      }
    }
    // cout << storageForMedians.size() << endl;
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
  
  // Comparison 1
  if(*a < *b) {
    swap(*a, *b);
  }

  // Comparison 2
  if(*c < *d) {
    swap(*c, *d);
  }

  // Comparison 3
  if(*a < *c) {
    swap(*c, *e);
    // Comparison 4
    if(*c < *d) {
      swap(*c, *d);
    }
  }
  else {
    swap(*a, *e);
    // Comparison 4
    if(*a < *b) {
      swap(*a, *b);
    }
  }

  // Comparison 5
  if(*a < *c) {
    swap(*a, *c);    
  }

  // Comparison 6: remaining 3 elements! 
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

void quickSelectMethodSix(vector<int>& theVector, const unsigned int& indexOfMedian) {
  quickSelectMethodSixHelper(theVector, 0, theVector.size() - 1, indexOfMedian);
}

void quickSelectMethodSixHelper(vector<int>& theVector, int left, int right, int k) {
  if(left + 24 <= right) {

    auto startPosition = theVector.begin() + left;
    auto endPosition = theVector.begin() + right;
    vector<int> vectorUpdate(startPosition, endPosition);
  
    const int& pivot = medianOfMedians(vectorUpdate);

    for(int i = 0; i < theVector.size(); ++i) {
      if(theVector.at(i) == pivot) {
        swap(theVector.at(i), theVector.at(right));
      }
    }
    
    //  Partition: 
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

    swap(theVector.at(i), theVector.at(right));
    
    if(k <= i)
      quickSelectMethodSixHelper(theVector, left, i - 1, k);
    else if(k > i + 1)
      quickSelectMethodSixHelper(theVector, i + 1, right, k);
  } 

  else {
    sort(theVector.begin(), theVector.end());
  } 
}

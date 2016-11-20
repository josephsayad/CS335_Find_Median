//
//  MethodControl.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/13/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>

#include "BinaryHeap.cpp"
#include "MethodControl.h"

#include "MethodOne.h"
#include "MedianTester.h"
#include "MethodThree.h"
#include "MethodFour.h"

/* Explicitly-Defined Default Constructor */

MethodControl::MethodControl() {}

/* Mutator Functions */

void MethodControl::setIndexOfMedian() {
  if(size() % 2 != 0) { indexOfMedian_ = size() / 2; } //  Odd: Middle element.
  else { indexOfMedian_ = (size() / 2) - 1; } //  Even: Lower of two middle elements.
}

/* Accessor Function */

unsigned int MethodControl::getIndexOfMedian() {
  return indexOfMedian_;
}

/* InputParser Functionality */

void MethodControl::parse() {
  theParser_.selectsDataFileNumber(1);
  theParser_.isReadingIntoVector();
  setIndexOfMedian();
}

/* Facilitate Functionality */ 

void MethodControl::runMethodOne() {
  isDataReady(); //  Eventually, will invoke once for each txt file.
  
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  cout << "Selection Sort (Method 1): " << methodOne(copyOfUnsortedInputData, getIndexOfMedian()) << "\n";
}

void MethodControl::medianCheck() {
  isDataReady();
  
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  cout << "Median Check (Method 2): " << runMedianTest(copyOfUnsortedInputData, getIndexOfMedian()) << "\n";
}

void MethodControl::runMethodThree() {
  isDataReady();

  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  cout << "In-Place Merge Sort (Method 3): " << methodThree(copyOfUnsortedInputData, getIndexOfMedian()) << "\n";
}

void MethodControl::runMethodFour() {
  isDataReady();

  //  Step 2: 
  BinaryHeap<int> copyOfDataInHeap(theParser_.getUnsortedInputData());
  int medianIndex = (size() / 2) - 1; 
  //  Even, or Odd - same for heap. You need to sort size() / 2 - 1 elements
  //  to get the median on top of the heap array: index 1. 

  cout << "In-Place Heap Sort (Method 4): " << methodFour(copyOfDataInHeap, medianIndex) << "\n";
}

/* Convenience Functions */

void MethodControl::displayInputData() const {
  for(auto i : theParser_.getUnsortedInputData()) {
  	cout << i << " ";
  }

  cout << "\n";
}

bool MethodControl::isEmpty() const {
  return theParser_.getUnsortedInputData().empty();
}

unsigned int MethodControl::size() const {
  return theParser_.getUnsortedInputData().size();
}

void MethodControl::isDataReady() const {
  if(isEmpty()) {
    cout << "ERROR: Has an input-data file been parsed?\n";
    exit(1);
  }
}
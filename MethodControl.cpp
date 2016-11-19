//
//  MethodControl.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/13/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include "MethodControl.h"

#include "MethodOne.h"
#include "MedianTester.h"
#include "MethodThree.h"

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
  isDataReady();
  
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  cout << "Selection Sort (Method 1): " << methodOne(copyOfUnsortedInputData, getIndexOfMedian()) << "\n";
}

void MethodControl::medianCheck() {
  isDataReady();
  
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  cout << "Median Check (Method 2): " << runMedianTest(copyOfUnsortedInputData, getIndexOfMedian()) << endl;
}

void MethodControl::runMethodThree() {
  isDataReady();

  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  cout << "In-Place Merge Sort (Method 3): " << methodThree(copyOfUnsortedInputData, getIndexOfMedian()) << "\n";
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
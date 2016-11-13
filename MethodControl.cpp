//
//  MethodControl.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/13/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>

#include "MethodControl.h"
#include "MedianTester.h"

/* Explicitly-Defined Default Constructor */

MethodControl::MethodControl() {}

/* InputParser Functionality */

void MethodControl::parse() {
  theParser_.selectsDataFileNumber(1);
  theParser_.isReadingIntoVector();
}

/* Convenience Functions */

void MethodControl::displayInputData() {
  for(auto i : theParser_.getUnsortedInputData()) {
  	cout << i << " ";
  }
  cout << "\n";
}

bool MethodControl::isEmpty() {
  return theParser_.getUnsortedInputData().empty();
}

unsigned int MethodControl::size() {
  return theParser_.getUnsortedInputData().size();
}

void MethodControl::medianCheck() {
  vector<int> v = theParser_.getUnsortedInputData();
  cout << "Median: " << runMedianTest(v) << endl;
}

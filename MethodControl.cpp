//
//  MethodControl.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/13/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <chrono>

#include "BinaryHeap.cpp"
#include "MethodControl.h"

#include "MethodOne.h"
#include "MedianTester.h"
#include "MethodThree.h"
#include "MethodFour.h"
#include "MethodFive.h"
#include "MethodSix.h"

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

void MethodControl::parse(const unsigned int& i) {
  theParser_.selectsDataFileNumber(i);
  theParser_.isReadingIntoVector();
  setIndexOfMedian();
}

void MethodControl::findMedians() {
  const unsigned int numberOfInputFiles = 9;
  double timeForMethod = 0.0;
  int theMedian;

  cout << "\n";
  cout << "******************************************************************************\n";

  for(unsigned int i = 1; i <= numberOfInputFiles; ++i) {
    parse(i);
    isDataReady();
    setIndexOfMedian();

    theMedian = runMethodOne(timeForMethod);
    cout << "METHOD: 1 INPUT FILE: " << i << " SIZE: " << size() << " ";
    if(theMedian != -1) { cout << "MEDIAN: " << theMedian << " "; }
    else { cout << "MEDIAN: Too Large: No run. "; }
    cout << "TIME: " << timeForMethod << " ms\n";

    theMedian = runMedianCheck(timeForMethod);
    cout << "METHOD: 2 INPUT FILE: " << i << " SIZE: " << size() << " ";
    cout << "MEDIAN: " << theMedian << " ";
    cout << "TIME: " << timeForMethod << " ms\n";

    theMedian = runMethodThree(timeForMethod);
    cout << "METHOD: 3 INPUT FILE: " << i << " SIZE: " << size() << " ";
    cout << "MEDIAN: " << theMedian << " ";
    cout << "TIME: " << timeForMethod << " ms\n";

    theMedian = runMethodFour(timeForMethod);
    cout << "METHOD: 4 INPUT FILE: " << i << " SIZE: " << size() << " ";
    cout << "MEDIAN: " << theMedian << " ";
    cout << "TIME: " << timeForMethod << " ms\n";

    theMedian = runMethodFive(timeForMethod);
    cout << "METHOD: 5 INPUT FILE: " << i << " SIZE: " << size() << " ";
    cout << "MEDIAN: " << theMedian << " ";
    cout << "TIME: " << timeForMethod << " ms\n";

    theMedian = runMethodSix(timeForMethod);
    cout << "METHOD: 6 INPUT FILE: " << i << " SIZE: " << size() << " ";
    cout << "MEDIAN: " << theMedian << " ";
    cout << "TIME: " << timeForMethod << " ms\n";

    cout << "******************************************************************************\n";
    timeForMethod = 0.0;
    clearList();
  }

  cout << "\n";
}

void MethodControl::clearList() {
  theParser_.empty();
}

/* Facilitate Functionality */ 

int MethodControl::runMethodOne(double& timeForMethod) {
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  
  auto start = chrono::steady_clock::now();
  int theMedian = methodOne(copyOfUnsortedInputData, getIndexOfMedian());
  auto end = chrono::steady_clock::now();
  auto diff = end - start;

  timeForMethod = chrono::duration <double, milli> (diff).count();
  return theMedian;
}

int MethodControl::runMedianCheck(double& timeForMethod) {
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();

  auto start = chrono::steady_clock::now();
  int theMedian = runMedianTest(copyOfUnsortedInputData, getIndexOfMedian());
  auto end = chrono::steady_clock::now();
  auto diff = end - start;

  timeForMethod = chrono::duration <double, milli> (diff).count();
  return theMedian;
}

int MethodControl::runMethodThree(double& timeForMethod) {
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  
  auto start = chrono::steady_clock::now();
  int theMedian = methodThree(copyOfUnsortedInputData, getIndexOfMedian());
  auto end = chrono::steady_clock::now();
  auto diff = end - start;

  timeForMethod = chrono::duration <double, milli> (diff).count();
  return theMedian;
}

int MethodControl::runMethodFour(double& timeForMethod) {
  //  Even, or Odd - same for heap. You need to sort size() / 2 - 1 elements
  //  to get the median on top of the heap array: index 1.
  //  Error on even, add random element.

  BinaryHeap<int> copyOfDataInHeap(theParser_.getUnsortedInputData());
  int medianIndex = (size() / 2) - 1;

  //  Issue with even number inputfiles resolved by making the heap odd - patch #1.
  if(size() % 2 == 0) { copyOfDataInHeap.insert(100); }

  auto start = chrono::steady_clock::now();
  int theMedian = methodFour(copyOfDataInHeap, medianIndex);
  auto end = chrono::steady_clock::now();
  auto diff = end - start;

  timeForMethod = chrono::duration <double, milli> (diff).count();
  return theMedian;
}

int MethodControl::runMethodFive(double& timeForMethod) {
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
    
  auto start = chrono::steady_clock::now();
  int theMedian = methodFive(copyOfUnsortedInputData, getIndexOfMedian());
  auto end = chrono::steady_clock::now();
  auto diff = end - start;

  timeForMethod = chrono::duration <double, milli> (diff).count();
  return theMedian;
}

int MethodControl::runMethodSix(double& timeForMethod) {
  vector<int> copyOfUnsortedInputData = theParser_.getUnsortedInputData();
  
  auto start = chrono::steady_clock::now();
  int theMedian = methodSix(copyOfUnsortedInputData, getIndexOfMedian());
  auto end = chrono::steady_clock::now();
  auto diff = end - start;

  timeForMethod = chrono::duration <double, milli> (diff).count();
  return theMedian;
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

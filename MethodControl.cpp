//
//  MethodControl.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/13/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "MethodControl.h"

#include "BinaryHeap.cpp"
#include "Output.h"

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
  //  If odd: Middle element.
  if(size() % 2 != 0) { indexOfMedian_ = size() / 2; }

  //  Else even: Smaller of two middle elements.
  else { indexOfMedian_ = (size() / 2) - 1; }
}

/* Accessor Function */

unsigned int MethodControl::getIndexOfMedian() {
  return indexOfMedian_;
}

/* InputParser Functionality */

void MethodControl::parse(const unsigned int& i) {
  //  (1) Set: "data/inputi.txt"
  theParser_.selectsDataFileNumber(i);

  //  (2) Parse: input file, and store in vector.
  theParser_.isReadingIntoVector();
}

void MethodControl::findMedians() {
  const unsigned int numberOfInputFiles = 9;
  
  Output theOutput; //  theOutput is a data structure for output-related data.
  double timeForMethod = 0.0;
  int theMedian;

  welcomePrompt();

  cout << "\n***********************************************************************************************************************\n";

  for(unsigned int i = 1; i <= numberOfInputFiles; ++i) {
    parse(i); //  (1) Parse the ith input file.
    isDataReady(); //  (2) Ensure parsing is successful via isDataReady() check.
    setIndexOfMedian(); //  (3) Set: the index of the median.

    /* Acquire the median, and time for each method below: */

    theMedian = runMethodOne(timeForMethod);
    theOutput.setOutput(1, i, size(), theMedian, timeForMethod);
    cout << theOutput;
    theGenerator_.storeMethodResults(theOutput);

    theMedian = runMedianCheck(timeForMethod);
    theOutput.setOutput(2, i, size(), theMedian, timeForMethod);
    cout << theOutput;
    theGenerator_.storeMethodResults(theOutput);

    theMedian = runMethodThree(timeForMethod);
    theOutput.setOutput(3, i, size(), theMedian, timeForMethod);
    cout << theOutput;
    theGenerator_.storeMethodResults(theOutput);

    theMedian = runMethodFour(timeForMethod);
    theOutput.setOutput(4, i, size(), theMedian, timeForMethod);
    cout << theOutput;
    theGenerator_.storeMethodResults(theOutput);

    theMedian = runMethodFive(timeForMethod);
    theOutput.setOutput(5, i, size(), theMedian, timeForMethod);
    cout << theOutput;
    theGenerator_.storeMethodResults(theOutput);

    theMedian = runMethodSix(timeForMethod);
    theOutput.setOutput(6, i, size(), theMedian, timeForMethod);
    cout << theOutput;
    theGenerator_.storeMethodResults(theOutput);

    cout << "***********************************************************************************************************************\n";
    timeForMethod = 0.0;
    clearList(); //  The parser must be cleared, and ready for the next input file.
  }
  
  cout << "\n";

  /* Grouping of times, calculation of average times, 
   * and the generation of the output file below: */
  
  theGenerator_.groupTimesPerSizeAndSort();
  theGenerator_.setAverageTimes();
  theGenerator_.generateOutputFile();
}

void MethodControl::clearList() {
  theParser_.empty();
}

/* Facilitate the Methods Functionality */ 

/* A Note ****************************************************************
 *************************************************************************
 * IN EACH OF THE "Facilitate the Methods" FUNCTIONALITIES:              *
 *                                                                       *
 * 1: A copy of [unsortedListOfIntegers_] is made before the invocation  *
 * of each method. This is intentionally written - we are timing the run *
 * of each algorithm - a copy of input would waste time.                 *
 *                                                                       *
 * 2: diff accounts for the difference between the end, and start times. *
 * Which is then set to timeForMethods. Each method below returns the    *
 * median, and the time via pass-by-reference.                           *
 *************************************************************************
 */

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
  //  Heap is built via Explicitly-Defined Constructor in BinaryHeap 
  //  implementation file. Heap sort: pop, and heapify until kth - 1
  //  smallest element. Then, pop kth smallest element: the median.

  BinaryHeap<int> copyOfDataInHeap(theParser_.getUnsortedInputData());
  int medianIndex = (size() / 2) - 1;

  //  Patch #2: Issue with even size - resolved by making the heap odd.
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

void MethodControl::welcomePrompt() const {
  cout << "\n************************************************************************\n";
  cout << "* Welcome to Joseph Sayad's execution of Project 1: Find The Medians   *\n";
  cout << "* Output Format: File Number * Method Number * Size * Median * Time    *\n";
  cout << "* Output File to be generated: output.txt                              *\n";
  cout << "************************************************************************\n";
}

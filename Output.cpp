//
//  Output.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <string>
#include "Output.h"

using namespace std;

/* Explicitly-Defined Default Constructor */ 

Output::Output() : methodNumber_(0), inputFileNumber_(0), sizeOfFile_(0) {}

/* Accessor Functions */

unsigned int Output::getMethodNumber() const { return methodNumber_; }

unsigned int Output::getInputFileNumber() const { return inputFileNumber_; }

unsigned int Output::getSizeOfFile() const { return sizeOfFile_; }

int Output::getTheMedian() const { return theMedian_; }

double Output::getTimeForMethod() const { return timeForMethod_; }

/* Mutator Functions */
    
void Output::setMethodNumber(unsigned int newNumber) { methodNumber_ = newNumber; }

void Output::setInputFileNumber(unsigned int newNumber) { inputFileNumber_ = newNumber; }

void Output::setSizeOfFile(unsigned int newSize) { sizeOfFile_ = newSize; }

void Output::setTheMedian(int newMedian) { theMedian_ = newMedian; }

void Output::setTimeForMethod(double newTime) { timeForMethod_ = newTime; }

void Output::setOutput(unsigned int newMethodNumber, unsigned int newFileNumber, unsigned int newSize, int newMedian, double newTime) {
  setMethodNumber(newMethodNumber);
  setInputFileNumber(newFileNumber);
  setSizeOfFile(newSize);
  setTheMedian(newMedian);
  setTimeForMethod(newTime);
}

/* Overloading the I/O Operators */

ostream& operator<<(ostream& out, const Output& theOutput) {
  string nameOfMethod = "";

  //  nameOfMethod is set depending on the value of [methodNumber_].
  if(theOutput.methodNumber_ == 1) { nameOfMethod = ": Selection Sort"; }
  else if(theOutput.methodNumber_ == 2) { nameOfMethod = ": Standard STL Sort"; }
  else if(theOutput.methodNumber_ == 3) { nameOfMethod = ": In-Place Merge Sort"; }
  else if(theOutput.methodNumber_ == 4) { nameOfMethod = ": In-Place Heap Sort"; }
  else if(theOutput.methodNumber_ == 5) { nameOfMethod = ": Quick Select with Median of Three"; }
  else { nameOfMethod = ": Quick Select with Median of Medians"; }

  const unsigned int selectionSortLimit = 1000000;
  
  //  If methodNumber is 1, and the selectionSortLimit has been reached:   
  if(theOutput.methodNumber_ == 1 && theOutput.sizeOfFile_ >= selectionSortLimit) {
    out << "Input " << theOutput.inputFileNumber_ << " * Method " << theOutput.methodNumber_ << nameOfMethod << " * Size: " 
    << theOutput.sizeOfFile_ << " * Median: Input size too large for selection sort." << " * Time: " << theOutput.timeForMethod_ << "\n";  
  }

  // Else: 
  else {
    out << "Input " << theOutput.inputFileNumber_ << " * Method " << theOutput.methodNumber_ << nameOfMethod << " * Size: " 
    << theOutput.sizeOfFile_ << " * Median: " << theOutput.theMedian_ << " * Time: " << theOutput.timeForMethod_ << "\n"; 
  }


  return out; 
}

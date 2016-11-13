//
//  InputParseAndFacilitate.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/12/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "InputParseAndFacilitate.h"
#include "MedianTester.h"

using namespace std;

/* Explicitly-Defined Default Constructor */

InputParseAndFacilitate::InputParseAndFacilitate() : dataFileNumber_("1") {}

/* Mutator Functions */

void InputParseAndFacilitate::setDataFileNumber(const unsigned int& initDataFileNumber) {
  if (initDataFileNumber > 9 || initDataFileNumber < 1) { 
    cout << "Data File (" << initDataFileNumber << ") is an invalid file number." << endl; 
    exit(1); 
  }  

  setDataFileNumberHelper(to_string(initDataFileNumber)); 
}

/* Accessor Function */
    
vector<int> InputParseAndFacilitate::getUnsortedVector() {
  return unsortedListOfIntegers_;
}

/* Parse Function */

void InputParseAndFacilitate::readIntoVector() {
  string fileName = "data/input" + dataFileNumber_ + ".txt"; 
  cout << "**********************************************" << endl;
  cout << "* " << fileName << " will be read into a vector. *" << endl;
  cout << "**********************************************" << endl;

  parseInputFile(fileName);
}

/* Convenience Functions */

void InputParseAndFacilitate::displayVector() {
  for(auto i : unsortedListOfIntegers_) {
  	cout << i << " ";
  }

  cout << "\n";
}

bool InputParseAndFacilitate::isEmpty() {
  return unsortedListOfIntegers_.empty(); 
}

unsigned int InputParseAndFacilitate::size() {
  return unsortedListOfIntegers_.size();
}


void InputParseAndFacilitate::medianCheck() {
  cout << "Median: " << runMedianTest(unsortedListOfIntegers_) << endl;
}

/* Private Helper Function */

void InputParseAndFacilitate::setDataFileNumberHelper(const string& initDataFileNumber) {
  dataFileNumber_ = initDataFileNumber; 
}

void InputParseAndFacilitate::parseInputFile(const string& inputFileName) {
  ifstream inputFileHandler(inputFileName);

  if(!inputFileHandler.is_open()) {
  	cout << "Input File (" << inputFileName << ") could not be read.\n";
  	inputFileHandler.close();
  	exit(1);
  }
    
  int nextInteger; 
  string stringInteger;

  while(!inputFileHandler.eof()) {
  	inputFileHandler >> stringInteger;
  	stringstream str(stringInteger);
  	str >> nextInteger;
  	unsortedListOfIntegers_.push_back(nextInteger);
  }

  inputFileHandler.close();
}

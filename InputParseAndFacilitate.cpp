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

using namespace std;

/* Explicitly-Defined Default Constructor */

InputParseAndFacilitate::InputParseAndFacilitate() : dataFileNumber_("1") {}

/* Mutator Functions */

void InputParseAndFacilitate::setDataFileNumber(const string& initDataFileNumber) {
  dataFileNumber_ = initDataFileNumber; 
}

void InputParseAndFacilitate::dataFileNumberCheck(const unsigned int& initDataFileNumber) {
  if (initDataFileNumber > 9 || initDataFileNumber < 1) { 
    cout << "Data File (" << initDataFileNumber << ") is an invalid file number." << endl; 
    exit(1); 
  }  

  setDataFileNumber(to_string(initDataFileNumber)); 
}

/* Parse Function */

void InputParseAndFacilitate::readIntoVector() {
  string fileName = "data/test" + dataFileNumber_ + ".txt"; 
  cout << "*****************************************" << endl;
  cout << fileName << " will be read into a vector!" << endl;
  cout << "*****************************************" << endl;

  parseInputFile(fileName);
}

/* Convenience Functions */

void InputParseAndFacilitate::displayVector() {
  for(unsigned int i = 0; i < unsortedListOfIntegers_.size(); ++i) {
  	cout << unsortedListOfIntegers_.at(i) << " ";
  }

  cout << endl;
}

bool InputParseAndFacilitate::isEmpty() {
  return unsortedListOfIntegers_.empty(); 
}

unsigned int InputParseAndFacilitate::size() {
  return unsortedListOfIntegers_.size();
}

/* Private Helper Function */

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

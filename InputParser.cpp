//
//  InputParser.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/12/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "InputParser.h"

using namespace std;

/* Explicitly-Defined Default Constructor */

InputParser::InputParser() : dataFileNumber_("1") {}

/* Mutator Functions */

void InputParser::selectsDataFileNumber(const unsigned int& initDataFileNumber) {
  if (initDataFileNumber > 9 || initDataFileNumber < 1) { 
    cout << "Data File (" << initDataFileNumber << ") is an invalid file number." << endl; 
    exit(1); 
  }  

  setDataFileNumberHelper(to_string(initDataFileNumber)); 
}

/* Accessor Function */
    
vector<int> InputParser::getUnsortedInputData() {
  return unsortedListOfIntegers_;
}

/* Parse Function */

void InputParser::isReadingIntoVector() {
  string fileName = "data/input" + dataFileNumber_ + ".txt"; 
  cout << "**********************************************" << endl;
  cout << "* " << fileName << " will be read into a vector. *" << endl;
  cout << "**********************************************" << endl;

  parseInputFile(fileName);
}

/* Private Helper Function */

void InputParser::setDataFileNumberHelper(const string& initDataFileNumber) {
  dataFileNumber_ = initDataFileNumber; 
}

void InputParser::parseInputFile(const string& initInputFileName) {
  ifstream inputFileHandler(initInputFileName);

  if(!inputFileHandler.is_open()) {
  	cout << "Input File (" << initInputFileName << ") could not be read.\n";
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

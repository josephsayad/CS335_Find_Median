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

  //  Included the string header for: to_string().
  setDataFileNumberHelper(to_string(initDataFileNumber)); 
}

/* Accessor Function */
    
vector<int> InputParser::getUnsortedInputData() const {
  return unsortedListOfIntegers_;
}

/* Parse Function */

void InputParser::isReadingIntoVector() {
  //  The input files are nested in the "data/" directory.
  string fileName = "data/input" + dataFileNumber_ + ".txt"; 
  parseInputFile(fileName);
}

/* Convenience Functions */

void InputParser::empty() {
  unsortedListOfIntegers_.clear();
}

void InputParser::printDivider() const {
  cout << "**************************************************************************************************\n\n";
}

/* Private Helper Function */

void InputParser::setDataFileNumberHelper(const string& initDataFileNumber) {
  dataFileNumber_ = initDataFileNumber; 
}

void InputParser::parseInputFile(const string& initInputFileName) {
  ifstream inputFileHandler(initInputFileName);
 
  if(!inputFileHandler.is_open()) {
  	
    //  Error Handling.
    cout << "Input File (" << initInputFileName << ") could not be read.\n";
    cout << "Are all 9 of the input files nested in a data sub-directory?\n";
    printDivider();
  	
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

  //  The while loop reads the last integer of the respective input file 
  //  twice. Patch #1: remove the repeated integer via pop_back(). 
  unsortedListOfIntegers_.pop_back();

  inputFileHandler.close();
}

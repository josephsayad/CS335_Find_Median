//
//  InputParser.h
//  Project 1
//
//  Created by Joseph Sayad on 11/12/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
using namespace std; 

class InputParser {
  public:
  	
  	/* Explicitly-Defined Default Constructor */
    InputParser();

    /* Mutator Functions */
    void selectsDataFileNumber(const unsigned int& initDataFileNumber);
    
    /* Accessor Function */
    vector<int> getUnsortedInputData();

    /* Parse Function */
    void isReadingIntoVector();

  private: 

  	/* Private Data Members */
  	string dataFileNumber_; 
    vector<int> unsortedListOfIntegers_;

    /* Private Helper Function */
    void setDataFileNumberHelper(const string& initDataFileNumber); 
    void parseInputFile(const string& inputFileName); 
};

#endif

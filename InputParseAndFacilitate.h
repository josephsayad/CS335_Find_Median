//
//  InputParseAndFacilitate.h
//  Project 1
//
//  Created by Joseph Sayad on 11/12/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef INPUTPARSEANDFACILITATE_H
#define INPUTPARSEANDFACILITATE_H

#include <vector>
using namespace std; 

class InputParseAndFacilitate {
  public:
  	
  	/* Explicitly-Defined Default Constructor */
    InputParseAndFacilitate();

    /* Mutator Functions */
    void setDataFileNumber(const unsigned int& initDataFileNumber);
    
    /* Accessor Function */
    vector<int> getUnsortedVector();

    /* Parse Function */
    void readIntoVector();

    /* Convenience Functions */
    void displayVector();
    bool isEmpty();
    unsigned int size();
    void medianCheck();

  private: 

  	/* Private Instance Members */
  	string dataFileNumber_; 
    vector<int> unsortedListOfIntegers_;

    /* Private Helper Function */
    void setDataFileNumberHelper(const string& initDataFileNumber); 
    void parseInputFile(const string& inputFileName); 
};

#endif

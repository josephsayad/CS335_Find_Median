//
//  MethodControl.h
//  Project 1
//
//  Created by Joseph Sayad on 11/13/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODCONTROL_H
#define METHODCONTROL_H

#include "InputParser.h"

using namespace std;

class MethodControl {
  public: 
  	
  	/* Explicitly-Defined Default Constructor */
    MethodControl();

    /* Mutator Functions */
    void setIndexOfMedian();

    /* Accessor Function */
    unsigned int getIndexOfMedian();

    /* InputParser Functionality */
    void parse();

    /* Facilitate Functionality */ 
    void runMethodOne();

    /* Convenience Functions */
    void displayInputData();
    bool isEmpty();
    unsigned int size();
    void medianCheck();
 
  private: 
    
    /* Private Data Members */
    InputParser theParser_;
    unsigned int indexOfMedian_;
};

#endif 
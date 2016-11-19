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
    void medianCheck(); //  Method 2
    void runMethodThree();

    /* Convenience Functions */
    void displayInputData() const;
    bool isEmpty() const;
    unsigned int size() const;
    void isDataReady() const;
 
  private: 
    
    /* Private Data Members */
    InputParser theParser_;
    unsigned int indexOfMedian_;
};

#endif 
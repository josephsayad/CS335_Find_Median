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
    void parse(const unsigned int& i);
    void findMedians();
    void clearList(); 

    /* Facilitate Functionality */ 
    int runMethodOne(double& timeForMethod);
    int runMedianCheck(double& timeForMethod);
    int runMethodThree(double& timeForMethod);
    int runMethodFour(double& timeForMethod);
    int runMethodFive(double& timeForMethod);
    int runMethodSix(double& timeForMethod);

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
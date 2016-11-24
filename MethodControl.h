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
#include "OutputFileGenerator.h"

using namespace std;

class MethodControl {
  public: 
  	
  	/* Explicitly-Defined Default Constructor */

    MethodControl();

    /* Mutator Functions */

    void setIndexOfMedian();    
    //  Precondition: Size function is implemented, and private member
    //  data [indexOfMedian_] must be defined in class environment. 
    //  Postcondition: Calculates, and sets the index of the median via 
    //  modulus operator: to determine whether the dataset is of even or
    //  odd length.

    /* Accessor Function */

    unsigned int getIndexOfMedian();
    //  Precondition: [indexOfMedian_] must have been set to correct value.
    //  Postcondition: Returns [indexOfMedian_].

    /* InputParser Functionality */

    void parse(const unsigned int& i);
    //  Precondition: Accepts variable of type const unsigned int by refer
    //  ence. InputParser class must be fully implemented.
    //  Postcondition: Invokes parsing functionality, and sets data member
    //  [indexOfMedian_] - dependent on the size of [unsortedListOfIntegers_].

    void findMedians();
    //  Precondition: All Methods, InputParser, Output and OutputFileGenerator
    //  classes must be implemented. 
    //  Postcondition: Iterates over the 9 input files. During each iteration 
    //  the file is parsed, the index of the median is set, each method is run,
    //  and time is accounted for. Outputs are printed to console, [theGenerator_]
    //  calculates for average times, and the output file is generated. 

    void clearList(); 
    //  Precondition: InputParser class must be fully implemented.
    //  Postcondition: Data member [theParser_] empties [unsortedListOfIntegers_]
    //  vector for next data-input file.

    /* Facilitate the Methods Functionality */ 

    int runMethodOne(double& timeForMethod);
    //  Precondition: Must include chrono header for time, and have Method One 
    //  implemented. 
    //  Postcondition: Returns theMedian via Selection Sort, and timeForMethod
    //  by reference.

    int runMedianCheck(double& timeForMethod);
    //  Precondition: Must include chrono header for time, have Method Two - 
    //  also referred to as MedianTester - implemented. The median returned 
    //  from this algorithm serves as an accuracy check for the correct median.
    //  Postcondition: Returns theMedian via Std::Sort, and timeForMethod by 
    //  reference.

    int runMethodThree(double& timeForMethod);
    //  Precondition: Must include chrono header for time, have Method Three
    //  implemented. 
    //  Postcondition: Returns theMedian via In-Place Merge Sort, and timeFor
    //  Method by reference.

    int runMethodFour(double& timeForMethod);
    //  Precondition: Must include chrono header for time, have Method Four 
    //  implemented. 
    //  Postcondition: Returns theMedian via In-Place Heap Sort, and timeFor
    //  Method by reference.

    int runMethodFive(double& timeForMethod);
    //  Precondition: Must include chrono header for time, have Method Five
    //  implemented. 
    //  Postcondition: Returns theMedian via Quick Select - Median of Three for
    //  the pivot - and timeForMethod by reference.

    int runMethodSix(double& timeForMethod);
    //  Precondition: Must include chrono header for time, have Method Six
    //  implemented. 
    //  Postcondition: Returns theMedian via Quick Select - Median of Medians for
    //  the pivot - and timeForMethod by reference.

    /* Convenience Functions */

    void displayInputData() const;
    //  Postcondition: Outputs the elements [unsortedListOfIntegers_] to console -
    //  which belongs to the [theParser_] data member.

    bool isEmpty() const;
    //  Postcondition: Outputs 1 if [unsortedListOfIntegers_] is empty - which 
    //  belongs to the [theParser_] data member.

    unsigned int size() const;
    //  Postcondition: Outputs size of [unsortedListOfIntegers_] - which belongs 
    //  to the [theParser_] data member.

    void isDataReady() const;    
    //  Postcondition: If [unsortedListOfIntegers_] is empty, then there is a
    //  problem with input-data file parsing: program aborts via exit(1).

    void welcomePrompt() const;
    //  Postcondition: Prints welcome prompt to console.
 
  private: 
    
    /* Private Data Members */

    InputParser theParser_; //  Instance of InputParser.
    OutputFileGenerator theGenerator_; //  Instance of OutputFileGenerator.
    unsigned int indexOfMedian_; //  Holds index of median for each input file.
};

#endif 
//
//  Output.h
//  Project 1
//
//  Created by Joseph Sayad on 11/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef OUTPUT_H
#define OUTPUT_H

using namespace std;

class Output {
  public:
    
    /* Explicitly-Defined Default Constructor */ 

    Output();    

    /* Accessor Functions */

    unsigned int getMethodNumber() const;
    // Postcondition: Returns a value of unsigned int.

    unsigned int getInputFileNumber() const;
    // Postcondition: Returns a value of unsigned int.

    unsigned int getSizeOfFile() const;
    // Postcondition: Returns a value of unsigned int.

    int getTheMedian() const;
    // Postcondition: Returns a value of int.

    double getTimeForMethod() const;
    // Postcondition: Returns a value of double.

    /* Mutator Functions */

    void setMethodNumber(unsigned int newNumber);
    // Precondition: Accepts variable of type unsigned int.
    // Postcondition: Sets [methodNumber_] to value of said variable.

    void setInputFileNumber(unsigned int newNumber);
    // Precondition: Accepts variable of type unsigned int.
    // Postcondition: Sets [inputFileNumber_] to value of said variable.

    void setSizeOfFile(unsigned int newSize);
    // Precondition: Accepts variable of type unsigned int.
    // Postcondition: Sets [sizeOfFile_] to value of said variable.

    void setTheMedian(int newMedian);
    // Precondition: Accepts variable of type int.
    // Postcondition: Sets [theMedian_] to value of said variable.


    void setTimeForMethod(double newTime);
    // Precondition: Accepts variable of type double.
    // Postcondition: Sets [timeForMethod_] to value of said variable.

    void setOutput(unsigned int newMethodNumber, unsigned int newFileNumber, unsigned int newSize, int newMedian, double newTime);
    // Precondition:
    // Postcondition:

    /* Overloading the I/O Operators */

    friend ostream& operator<<(ostream& out, const Output& theOutput); 
    //  Precondition: This friend function requires two arguments: output, and an object of type ostream
    //  (e.g. cout) - the lhs operand. Thus, the iostream library must be included.
    //  Postcondition: Prints output-related data from respective "output containers" to the console.

  private: 
  	
  	/* Private Data Members */

    unsigned int methodNumber_; //  Algorithm used.
    unsigned int inputFileNumber_; //  File worked on.
    unsigned int sizeOfFile_; //  Size of file worked on.
    int theMedian_; //  Median generated from algorithm.
    double timeForMethod_; //  Time it took: milliseconds (ms)
};

#endif

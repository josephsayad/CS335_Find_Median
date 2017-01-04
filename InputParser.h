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

    /* Mutator Function */

    void selectsDataFileNumber(const unsigned int& initDataFileNumber);
    //  Precondition: Accepts an variable of type unsigned int by reference. 
    //  The value should reside within the range of 1 to 9. 
    //  Postcondition: Invokes to_string() functionality, and passes string 
    //  to private helper function - the string denotes an appropriate input 
    //  file to be parsed.
    
    /* Accessor Function */

    vector<int> getUnsortedInputData() const;
    //  Precondition: Must include the vector header, and declare object of 
    //  type vector. Here said object is: [unsortedListOfIntegers_].
    //  Postcondition: Returns unsortedListOfIntegers_ by value.

    /* Parsing Functionality */

    void isReadingIntoVector();
    //  Postcondition: Invokes parseInputFile functionality.

    /* Convenience Functions */

    void empty();
    //  Precondition: Must include the vector header, and declare object of 
    //  type vector. Here said object is: [unsortedListOfIntegers_].
    //  Postcondition: Clears [unsortedListOfIntegers_] of all elements.

    void printDivider() const;
    //  Postcondition: Prints a series of '*' characters to console for the
    //  purpose of display aesthetic. 

  private: 

    /* Private Data Members */

    string dataFileNumber_; //  Indicates file being parsed.
    vector<int> unsortedListOfIntegers_; //  Holds unsorted list of integers.

    /* Private Helper Function */

    void setDataFileNumberHelper(const string& initDataFileNumber);
    //  Precondition: Accepts a variable of type string by reference.
    //  Postcondition: Constructs file name - which includes the directory 
    //  that the input files can be found. Then, passes the path-to-the-file 
    //  to the parseInputFile() method.

    void parseInputFile(const string& initInputFileName); 
    //  Precondition: Accepts a variable of type string by reference. Must 
    //  include the C++ STL fstream, and sstream header files. 
    //  Postcondition: Parses an input file - specified by initInputFileName
    //  - and reads into [unsortedListOfIntegers_].
};

#endif

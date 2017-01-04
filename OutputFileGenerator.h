//
//  OutputFileGenerator.h
//  Project 1
//
//  Created by Joseph Sayad on 11/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef OUTPUTFILEGENERATOR_H
#define OUTPUTFILEGENERATOR_H

#include <vector>
#include "Output.h"

using namespace std;

class OutputFileGenerator {
  public: 
    
    /* Explicitly-Defined Default Constructor */ 

  	OutputFileGenerator();

    /* Output Storage Functionality */

    void storeMethodResults(Output& outputGenerated);
    //  Precondition: Must implement the Output Class, and output 
    //  provided.
    //  Postcondition: Stores the output generated - from each run -
    //  into [theOutputStore_].

    /* Average Time of Algorithm Per Size Computation */

    void groupTimesPerSizeAndSort();
    //  Precondition: Must define [times_] vector as calss data mem
    //  ber. 
    //  Postcondition: Depending on the size of the file, and the 
    //  type of algorithm used - the times are summed. IE: times for
    //  selection sort at size 1000 will be added to index 1. 

    void setAverageTimes();
    //  Precondition: [times_] vector is setup. 
    //  Postcondition: Iterates over the [times_] vector, and places 
    //  times for the SAME methods next to one another in the [averageTimes_]
    //  vector. While pushing said times, the average is taken: (timeOne + timeTwo
    //  + timeThree) / 3.

    /* Output File Generation */

    void generateOutputFile();
    //  Precondition: [averageTimes_] vector is setup, and output file name defined.
    //  Postcondition: Writes the average times - for each sort per size - to file. 
    //  The output file can be found in the root directory. 

    /* Convenience Function */

    unsigned int size() const;
    //  Postcondition: Outputs size of [theOutputStore_] - the number of elements
    //  of type Output. 

  private: 
    
    /* Private Data Members */

    vector<Output> theOutputStore_; //  Storage of all outputs.
    vector<double> times_; //  Storage of all times summed.
    vector<double> averageTimes_; //  Storage of averages.
};

#endif
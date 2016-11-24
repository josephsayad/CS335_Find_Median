//
//  OutputFileGenerator.cpp
//  Project 1
//
//  Created by Joseph Sayad on 11/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "OutputFileGenerator.h"

using namespace std;

/* Explicitly-Defined Default Constructor */ 

OutputFileGenerator::OutputFileGenerator() {
  //  Initialize summation of times to 0: before output
  //  recieved. The three times for each method per size
  //  will be stored in 1 of the 18 indexes of [times_].

  for (int i = 0; i <= 17; ++i) {
    times_.push_back(0.0);
  }
}

/* Output Storage Functionality */

void OutputFileGenerator::storeMethodResults(Output& outputGenerated) {
  theOutputStore_.push_back(outputGenerated);
}

/* Average Time of Algorithm Per Size Computation */

void OutputFileGenerator::groupTimesPerSizeAndSort() {
  /* Sizes: hard-coded. */

  const unsigned int size_one = 1000;
  const unsigned int size_two = 31623;
  const unsigned int size_three = 1000000;

  //  For: each object of type Output... 
  for(unsigned int i = 0; i < theOutputStore_.size(); ++i) {

    unsigned int method = theOutputStore_.at(i).getMethodNumber();
    double time = theOutputStore_.at(i).getTimeForMethod(); 

    //  If: the object is read from a file of size_one. 
    if(theOutputStore_.at(i).getSizeOfFile() == size_one) {
      if(method == 1) {
        times_.at(0) += time; 
      }
      else if(method == 2) {
      	times_.at(1) += time;
      }
      else if(method == 3) {
      	times_.at(2) += time; 
      }
      else if(method == 4) {
      	times_.at(3) += time;
      }
      else if(method == 5) {
        times_.at(4) += time;
      }
      else if(method == 6) {
        times_.at(5) += time;
      } 
    } 
  
    //  Else if: the object is read from a file of size_two. 
    else if(theOutputStore_.at(i).getSizeOfFile() == size_two) {
      if(method == 1) {
        times_.at(6) += time;
      }
      else if(method == 2) {
      	times_.at(7) += time;
      }
      else if(method == 3) {
      	times_.at(8) += time; 
      }
      else if(method == 4) {
      	times_.at(9) += time;
      }
      else if(method == 5) {
        times_.at(10) += time;
      }
      else if(method == 6) {
        times_.at(11) += time;
      }
    }

    //  Else if: the object is read from a file of size_three. 
    else if(theOutputStore_.at(i).getSizeOfFile() == size_three){
      if(method == 1) {
        times_.at(12) += time;
      }
      else if(method == 2) {
      	times_.at(13) += time;
      }
      else if(method == 3) {
      	times_.at(14) += time; 
      }
      else if(method == 4) {
      	times_.at(15) += time;
      }
      else if(method == 5) {
        times_.at(16) += time;
      }
      else if(method == 6) {
        times_.at(17) += time;
      }
    }
  } /* Output With Equivalent Algorithm, and File Size: Times Are Summed */
}

void OutputFileGenerator::setAverageTimes() {
  double three = 3.0;

  //  Averages taken, and pushed to vector.
  for(int i = 0; i < 6; ++i) {
  	averageTimes_.push_back((times_.at(0 + i) /= three));
  	averageTimes_.push_back((times_.at(6 + i) /= three));
  	averageTimes_.push_back((times_.at(12 + i) /= three));
  }
}

/* Output File Generation */

void OutputFileGenerator::generateOutputFile() {
  string baseFileName = "output";
  string extension = ".txt";
  string fileName = baseFileName + extension;

  ofstream outFile(fileName);

  outFile << "Output File: Calculating the Statistics\n\n";

  string methodNames[6];
  methodNames[0] = "Selection Sort";
  methodNames[1] = "Standard STL Sort";
  methodNames[2] = "In-Place Merge Sort";
  methodNames[3] = "In-Place Heap Sort";
  methodNames[4] = "Quick Select";
  methodNames[5] = "Median of Medians";

  int j = 0;
  
  for(int i = 0; i < 6; ++i) {
  	outFile << "***************************************\n\n";
  	outFile << "Average Time of " << methodNames[i] << " on input files of size 1000: " << averageTimes_.at(j) << "ms\n";
    outFile << "Average Time of " << methodNames[i] << " on input files of size 31623: " << averageTimes_.at(++j) << "ms\n"; 
    outFile << "Average Time of " << methodNames[i] << " on input files of size 1000000: " << averageTimes_.at(++j) << "ms\n";
    outFile << "\n";
    ++j;
  }
}

/* Convenience Functions */

unsigned int OutputFileGenerator::size() const {
  return theOutputStore_.size();
}

#include <iostream>
#include "InputParseAndFacilitate.h"

using namespace std;

int main() {
  InputParseAndFacilitate parserOne;
  parserOne.dataFileNumberCheck(1);
  parserOne.readIntoVector();
  cout << "There are " << parserOne.size() << " strings in the input file!" << endl;
  return 0;
}

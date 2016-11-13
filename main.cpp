#include <iostream>
#include "InputParseAndFacilitate.h"

using namespace std;

int main() {
  InputParseAndFacilitate theParser;
  theParser.setDataFileNumber(1);
  theParser.readIntoVector();
  theParser.medianCheck();
  return 0;
}
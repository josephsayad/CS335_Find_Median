#include <iostream>
#include "MethodControl.h"

using namespace std;

int main() {
  MethodControl controllerOne;
  controllerOne.parse();
  controllerOne.runMethodOne();
  controllerOne.medianCheck();
  controllerOne.runMethodThree();
  controllerOne.runMethodFour();
  controllerOne.displayInputData();
}
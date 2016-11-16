#include <iostream>
#include "MethodControl.h"

using namespace std;

int main() {
  MethodControl controllerOne; 
  controllerOne.parse();
  controllerOne.runMethodOne();
  return 0;
}
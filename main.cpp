#include <iostream>
#include "MethodControl.h"
#include "BinaryHeap.cpp"

using namespace std;

int main() {
  MethodControl controllerOne;
  controllerOne.parse();
  controllerOne.runMethodOne();
  controllerOne.medianCheck();
  controllerOne.runMethodThree();
}
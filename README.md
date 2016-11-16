# Programming Assignment 1: The Median of an Unsorted List

## About The Project 

In this assignment: you will implement, and compare different methods for finding the median of an unsorted list. There are 6 methods total (each with a respective .cpp file, and header file).

### Expected execution structure

The resulting program will compile, and execute via the following commands:

	make all
	./FindMedian

See the **data** directory for input data files.

### The Methods: Solidified Plan for Algorithms

(... explain each steps of each algorithm ...)

### A Driver Class: InputParser

An instance of the `InputParser` class will serve as *one* of the *driver programs*, which will read the a text file of unsorted integers into an array-based data structure.

*Array-Based Data Structure Hand-off*: The question arises - How do we invoke each algorithm on the original input? We cannot use an altered (sorted) array as input for any of the methods. We can pass the array-based data structure by value, ... or we can explicitly make a copy, and pass the copy by reference.

### A Driver Class: MethodControl

An instance of the `MethodControl` class facilitates the invocation of each method on the individual vectors containing data from the parsed text files. It also can run `medianCheck()` functionality as a final accuracy check.

### The Median Tester 

An instance of `MedianTester` will take the array-based data structure of sorted integers - provided by an instance of `Input Parser` and sorted by a sorting algorithm - and check to see the result if each method is correct. It will find the median of the list in `O(N)` time.

**Note: `runTest()` takes copies the vector by reference, and sorts the vector - this is to be done after all methods have been invoked, and answer is returned by each individual method. After the sort, finding the median, and the checking - the vector of sorted integers will be deleted to save space. Then, the next input text file may be parsed, and the process will repeat.

### Functions To Be Implemented

1. `MethodOne`

2. `MethodTwo`

3. `MethodThree`

4. `MethodFour`

5. `MethodFive`

6. `MethodSix`

### Classes To Be Implemented

1. `InputParser`
2. `MethodControl`

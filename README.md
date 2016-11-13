# Programming Assignment 1: The Median of an Unsorted List

## About The Project 

In this assignment: you will implement, and compare different methods for finding the median of an unsorted list. There are 6 methods total - each with a respective .cpp file and header file.

### Expected execution structure

The resulting program will compile, and execute via the following commands:

	make all
	./FindMedian <input file name>

See the **data** directory for input data files.

### The Methods: Solidified Plan for Algorithms

(... explain each steps of each algorithm ...)

### The Driver Program [InputParseAndFacilitate]

An instance of the `InputParseAndFacilitate` class will serve as the **driver program**, which will read the a text file of unsorted integers into an array-based data structure. Then, the instance of the class will facilitate the invocation of each method on said data structure - resulting in an outputted median.

*Hand Off of Array-Based Data Structure* - The question arises: How do we invoke each algorithm on the original input? We cannot use an altered (sorted) array as input. This contradicts the purpose of the project! We can pass the array-based data structure by value ... Or we can explicitly make a copy, and pass a pointer to that copy. **Note: when timing how long each algorithm takes - try not to include the steps put into parsing the input text file, or copying the array-based data structure.**

### The Median Tester 

An instance of `MedianTester` will take the array-based data structure of sorted integers - provided by the **driver program** and sorted by a sorting algorithm - and check to see that the result of each method is correct. It will find the median of the list in `O(N)` time.

### Functions To Be Implemented

1. `MethodOne`

2. `MethodTwo`

3. `MethodThree`

4. `MethodFour`

5. `MethodFive`

6. `MethodSix`

### Classes To Be Implemented

1. `InputParseAndFacilitate`
2. `MedianTester`

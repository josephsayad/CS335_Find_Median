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

An instance of `MedianTester` will take the array-based data structure of sorted integers - provided by the **driver program** and sorted by a sorting algorithm - and check to see the result of each method is correct. It will find the median of the list in `O(N)` time.

**Note: `runTest()` takes copies the vector by reference, and sorts the vector - this is to be done after all methods have been invoked, and answer is returned by each individual method. After the sort, finding the median, and the checking - the vector of sorted integers will be deleted to save space. Then, the next input text file may be parsed, and the process will repeat.

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

### Questions

1. Would it be fine to house all 6 methods in 1 class, or should we place each method in a cpp/header files.
2. When passing the unsortedListOfInts to each method - we do not want to modify the contents of the actual list. We'll need the list unsorted for the next method. So I thought of passing the vector by value into each function! A problem arises. Is this a legitimate problem: the time function takes into account the copying of contents into the vector local to that method. If this is a legitimate problem - should I do a copy outside each of the methods? 
3. MedianTester Question: "you'll probably want to write a program to check that your result is correct. It should be trivial to check that a number is the median of a list in linear time." To do this, should we use the std::sort, and then find the median in linear time (invocation of size function takes O(N) steps.)
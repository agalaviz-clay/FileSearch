# File Search

### Motivation

The goal of this exercise is to create a working program to search a set of text files for the given search term or phrase (single token), and return results in order of relevance.

Relevancy is defined as number of times the exact term or phrase appears in the document.

There are three methods for searching the files:
* Simple string matching
* Text search using regular expressions
* Preprocess the content and then search the index

### How to Run

To run this program successfully, you will need to download this program with all of its associated files.
Once you have them downloaded save them to a directory of your choosing you will need to open the terminal
and navigate to the directory where you saved the folder.

1) Navigate to the `/src` directory that stores all the source code
2) Run the command `g++ main.cc search.cc simple.cc regex.cc preprocess.cc`
   * This use the [GNU Compiler Collection (g++)](https://gcc.gnu.org/) to compile and link the C++ source files
   * The output will be a executable program called `a.out`
3) Execute the executable program with `./a.out`
4) The program runs and will prompt the user to enter a search term and search method, execute the search, and return results. 

For example:
```
Enter the search term: <user enters search term>
Enter 1 for String Match, 2 for Regular Expression, 3 for Indexed: <use enters number>
Search results:
      File2.txt - X matches
      File1.txt - X matches
      File3.txt - X matches
Elapsed time: 40 ms
```

### Performance Test

`performance.cc` is a file that runs all 3 search algorithms consecutively and will print out how long each
algorithm takes after running them with a random search term, 2 million times. (This is a very naive performance strategy!)

1) Navigate to the `/src` directory that stores all the source code
2) Run the command `g++ performance.cc search.cc simple.cc regex.cc preprocess.cc -o perf` to compile and link the performance test
3) Execute the output executable program with `./perf.out`

### Notes

I have designed this program to handle inputs that can either be a single word, a phrase separated by spaces, or
a regular expression. My algorithm is case-sensitive so this allows for the user to search for a precise word.
So the word "hello" and "Hello" would be deemed as different words.

### Wishlist
* Refactor to use programming standards and idiomatic C++
   * *I wrote this program while in college, so there are some unconventional patterns used!*
* Rewrite in Java (or write a Java/Python equivalent)
* Rewrite performance to be more efficient (consider benchmarking libraries like [Google Benchmark](https://github.com/google/benchmark) or [Criterion](https://bheisler.github.io/criterion.rs/book/))
* Create unit tests (maybe Google Test, Catch2, or doctest testing frameworks)

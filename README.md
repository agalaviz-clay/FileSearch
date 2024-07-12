# File Search

__Motivation__

The goal of this exercise is to create a working program to search a set of text files for the given search term or phrase (single token), and return results in order of relevance.

Relevancy is defined as number of times the exact term or phrase appears in the document.

There are three methods for searching the files:
* Simple string matching
* Text search using regular expressions
* Preprocess the content and then search the index

__How to Run__

To run this program successfully, you will need to download this program with all of its associated files.
Once you have them downloaded save them to a directory of your choosing you will need to open the terminal
and navigate to the directory where you saved the folder.

Like so: `cd pathToDirectory/FileSearch/src`

after that you will need to type this `g++ main.cc search.cc simple.cc regular.cc preprocess.cc` which will compile the code and create an executable
called `a.out`. At this point you will type `./a.out` to run the executable.

The terminal will now prompt the user to enter a search term and search method, execute the search, and
return results. For instance:
```
Enter the search term: <user enters search term>
Enter 1 for String Match, 2 for Regular Expression,3 for Indexed <use enters number>
Search results:
      File2.txt - X matches
      File1.txt - X matches
      File3.txt - X matches
Elapsed time: 40 ms
```

__Performance Test__

performance.cc is a provided file that runs all 3 search algorithms consecutively it will print out how long each
algorithm takes after running each algorithm with a random search term, 2 million times. (This is a very naive performance strategy!)

1. Navigate to the folder by typing cd pathToDirectory/FileSearch/src in the terminal
2. Type `g++ performance.cc search.cc simple.cc regular.cc preprocess.cc` to compile performance test
3. Type `./a.out` to run

__Notes__

I have designed this program to handle inputs that can either be a single word, a phrase separated by spaces, or
a regular expression. My algorithm is case sensitive so this allows for the user to search for a precise word.
So the word "hello" and "Hello" would be deemed as different words.

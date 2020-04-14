#ifndef SEARCH_H_
#define SEARCH_H_
#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>  // used for the sort() function

using namespace std;

class Search {

public:
  Search();

  void StringToCharacterPtr(string str, char *ptr);

  // find the number of occurences of a key word or phrase in a single file
  virtual int FindMatches(string fileName) = 0;

  // Prints to the screen the files in order respective to relevancy with their
  // number of matches, as well as print out the speed of which this search ran
  void DisplayResults();

  // will split the phrase and put each word into the vector
  // individually seperated by spaces
  void SplitSearchTerm(string searchTerm);

  void StoreMatchesFound();

  void SortByRelevancy();

protected:
  vector<string> phrase;
  vector<tuple<int,string>> fileInfo;
};
#endif

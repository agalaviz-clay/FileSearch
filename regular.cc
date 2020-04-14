#include "regular.h"

Regular::Regular(string searchTerm) {
  // sets the regular expression to be the passed in one
  searchTerm_ = searchTerm;
}

int Regular::FindMatches(string fileName) {
  ifstream file;
  file.open(fileName);
  if (!file.is_open()) {
    cout << "Error: This file could not open" << endl;
    return 0;
  }

  // the amount of times the word/phrase has been seen
  int numberOfOccurences = 0;
  string singleWord;
  regex searchTermReg(searchTerm_);
  // while we are not eof, put the current word inside of singleWord
  while(file >> singleWord) {
    // returns true if the word in file is the same as this regular expression
    // orI should say follows the pattern of this regular expression
    if (regex_match(singleWord,searchTermReg)) {
      numberOfOccurences += 1;
    }
  }
  return numberOfOccurences;
}

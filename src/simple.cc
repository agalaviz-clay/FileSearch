#include "simple.h"


Simple::Simple(string searchTerm) {
  SplitSearchTerm(searchTerm);
}

int Simple::FindMatches(string fileName) {
  ifstream file;
  file.open(fileName);
  if (!file.is_open()) {
    cout << "Error: This file could not open" << endl;
    // what should I do in case of error
    return 0;
  }

  // keeps track of what word im going to be looking at in the searchTerm_
  // which was split up by spaces.
  int searchTermPosition = 0;

  // the amount of times the word/phrase has been seen
  int numberOfOccurences = 0;
  string singleWord;

  // while we are not eof, put the current word inside of singleWord
  while(file >> singleWord) {
    int size1 = singleWord.length();
    int size2 = phrase[searchTermPosition].length();
    char fileWord[size1+1];
    char phraseWord[size2+1];

    // convert string to char[]
    StringToCharacterPtr(singleWord,fileWord);
    StringToCharacterPtr(phrase[searchTermPosition],phraseWord);

    // if the word I'm currently looking at in the file is the same as the
    // word I'm currently looking at in the passed in searchTerm phrase.
    if ( strcmp(fileWord, phraseWord ) == 0 ) {
        // if im at the last element in the vector that holds my searchTerm_
        // split up by spaces, then I found a word/phrase
        if ( searchTermPosition == phrase.size()-1 ) {
            numberOfOccurences += 1;
            // reset to start the search over
            searchTermPosition = 0;
        } else {
          // move to the next word in the phrase
          searchTermPosition += 1;
        }
    } else {
        // reset the search
       searchTermPosition = 0;
    }
  }
  file.close();
   // return the number of times the word/phrase was found
  return numberOfOccurences;
}

#include "preprocess.h"


Preprocess::Preprocess(string searchTerm) {
  searchTerm_ = searchTerm;

  // put the string in a  vector<string> phrase;
  // that are words seperated by spaces
  SplitSearchTerm(searchTerm_);

  vector<string> fileNames;
  fileNames.push_back("french_armed_forces.txt");
  fileNames.push_back("hitchhikers.txt");
  fileNames.push_back("warp_drive.txt");
  map<string, int> frenchMap;
  map<string, int> hitchMap;
  map<string, int> warpMap;

  // initialize the   map< string , map<string, int> > maps
  // now I can use the string of the file name to directly look
  // up the map that is created to store all the words in the file
  maps.insert(pair<string, map<string, int>>("french_armed_forces.txt",
              frenchMap));
  maps.insert(pair<string, map<string, int>>("hitchhikers.txt", hitchMap));
  maps.insert(pair<string, map<string, int>>("warp_drive.txt",warpMap));

  // loop through all 3 files and StoreInMap() will process the entire file
  // into the files respective map that holds is of type <string, int>
  for (int i = 0; i < 3; i++) {
    StoreWordsInMap(fileNames[i]);
  }
}

int Preprocess::FindMatches(string fileName) {
  // returns the number of occurences of a search term for this file
  return (maps[fileName])[searchTerm_];

}


// all 3 maps stored in vector now have ever word in the file and
// the searchTerm in there stored with the respective number of occurences
void Preprocess::StoreWordsInMap(string fileName) {

  // get me the map associated with the provided file name
  // and inside of it put the provided searchTerm_ as the first key with 0
  // as its value. This will let me keep track of how many times I have seen
  // the phrase
  maps[fileName].insert(pair<string, int>(searchTerm_, 0));
  ifstream file;
  file.open(fileName);
  if (!file.is_open()) {
    cout << "error: couldn't open up the file" << endl;
  }

  // keeps track of what word im going to be looking at in the searchTerm_
  // which was split up by spaces.
  int searchTermPosition = 0;
  string singleWord;
  // while we are not eof, put the current word inside of singleWord
  while(file >> singleWord) {
    // count returns 1 if found in map and 0 if didn't find in map
    // so if this key exist in the map
    if (maps[fileName].count(singleWord) > 0 ) {
      // increment the count
      maps[fileName][singleWord] += 1;
    } else {
      // it didn't exists in the map so put it in the map with a count of 1
      maps[fileName].insert(pair<string, int>(singleWord, 1));
    }

    // this check is to make sure that I will not deal with a phrase that has
    // only 1 word in it, if I didn't make this if statement, I would end up
    // with double the amount found cases of the searchTerm_
    if (phrase.size() > 1) {
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
              // then increment the count of this phrase in the map += 1;
              maps[fileName][searchTerm_] += 1;
              // reset to start the search over
              searchTermPosition = 0;
          } else {
            // means we did find a match but there are still more words to
            // check in the phrase to see if we found the full phrase
            // move to the next word in the phrase
            searchTermPosition += 1;
          }
      } else {
         // didn't find a match
         // reset the search
         searchTermPosition = 0;
      }
    }
  }
  file.close();
}

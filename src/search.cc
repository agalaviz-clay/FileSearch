#include "search.h"
Search::Search() {
  fileInfo.push_back( tuple<int,string>(0, "french_armed_forces.txt"));
  fileInfo.push_back( tuple<int,string>(0, "hitchhikers.txt"));
  fileInfo.push_back( tuple<int,string>(0, "warp_drive.txt"));
}

void Search::StringToCharacterPtr(string str, char *ptr) {
  strcpy(ptr, str.c_str());
}

// takes a keyword/phrase and breaks it up by spaces
// stores each individual word in vector of strings
void Search::SplitSearchTerm(string searchTerm) {
  char delim[] = " ";
  int n = searchTerm.length();
  char char_array[n+1];
  strcpy(char_array, searchTerm.c_str());
  char *singleWord = strtok(char_array,delim);
  while (singleWord) {
    // store the individual word in the vector
    phrase.push_back(singleWord);
    singleWord = strtok(NULL, delim);
  }
}


void Search::StoreMatchesFound() {
  vector<string> fileNames;
  fileNames.push_back("french_armed_forces.txt");
  fileNames.push_back("hitchhikers.txt");
  fileNames.push_back("warp_drive.txt");

  // loops through each file finds the number of occurences of searchTerm_
  // in the file and stores that information in
  // vector<tuple<int,string>> fileInfo;
  for (int i = 0; i < 3; i++) {
    int num = FindMatches(fileNames[i]);
    get<0>(fileInfo[i]) = num;
  }
}



void Search::SortByRelevancy() {
  // sorts the vector to have lowest relevancy at the start of the vector
  // and the higest at the end of the vector
  sort(fileInfo.begin(), fileInfo.end());
}

void Search::DisplayResults() {
  // print each file and number of matches on screen
  cout << "Search results:" << endl;
  // going in reverse order because at the start of vector is the lowest number
  // and at the end of vector is the higest number of matches
  for (int i = fileInfo.size()-1; i >= 0; i--) {
    cout << "    " << get<1>(fileInfo[i]) << "-" << get<0>(fileInfo[i])
              << " matches"<< std::endl;
  }
}

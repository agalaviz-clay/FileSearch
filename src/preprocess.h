#ifndef PREPROCESS_H_
#define PREPROCESS_H_
#include "search.h"
#include <map>


using namespace std;


class Preprocess : public Search {
  public:
    Preprocess(string searchTerm);

    // used by StoreMatchesFound to put the int found into the respective file
    int FindMatches(string fileName);

    void StoreWordsInMap(string fileName);

  private:
    //  the string is the filename.txt then the map<string, int> is the
    // words, and the number of occurences
    map<string,map<string,int>> maps;

    string searchTerm_;

};
#endif

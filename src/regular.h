#ifndef REGULAR_H_
#define REGULAR_H_
#include "search.h"
#include <regex>

using namespace std;

class Regular : public Search {
  public:
    Regular(string searchTerm);

    // used by StoreMatchesFound to put the int found into the respective file
    int FindMatches(string fileName);

  private:
    string searchTerm_;

};
#endif

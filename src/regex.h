#ifndef REGEX_H_
#define REGEX_H_
#include "search.h"
#include <regex>

using namespace std;

class Regex : public Search {
    public:
        Regex(string searchTerm);
        int FindMatches(string fileName);

    private:
        string searchTerm;
};
#endif

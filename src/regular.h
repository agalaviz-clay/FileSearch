#ifndef REGULAR_H_
#define REGULAR_H_
#include "search.h"
#include <regex>

using namespace std;

class Regular : public Search {
    public:
        Regular(string searchTerm);
        int FindMatches(string fileName);

    private:
        string searchTerm_;
};
#endif

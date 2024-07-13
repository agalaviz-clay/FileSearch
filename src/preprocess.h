#ifndef PREPROCESS_H_
#define PREPROCESS_H_
#include "search.h"
#include <map>

using namespace std;

class Preprocess : public Search {
    public:
        Preprocess(string searchTerm);
        int FindMatches(string fileName);
        void StoreWordsInMap(string fileName);

    private:
        map<string,map<string,int>> maps;
        string searchTerm_;
};
#endif

#include "regular.h"

Regular::Regular(string searchTerm) {
    searchTerm_ = searchTerm;
}

int Regular::FindMatches(string fileName) {
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error: This file could not open" << endl;
        return 0;
    }

    int numberOfOccurences = 0;
    string singleWord;
    regex searchTermReg(searchTerm_);
    while(file >> singleWord) {
        if (regex_match(singleWord,searchTermReg)) {
            numberOfOccurences += 1;
        }
    }
    return numberOfOccurences;
}

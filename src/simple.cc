#include "simple.h"

Simple::Simple(string searchTerm) {
    SplitSearchTerm(searchTerm);
}

int Simple::FindMatches(string fileName) {
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error: This file could not open" << endl;
        return 0;
    }

    int searchTermPosition = 0;
    int numberOfOccurences = 0;
    string singleWord;

    while(file >> singleWord) {
        int size1 = singleWord.length();
        int size2 = phrase[searchTermPosition].length();
        char fileWord[size1+1];
        char phraseWord[size2+1];

        StringToCharacterPtr(singleWord,fileWord);
        StringToCharacterPtr(phrase[searchTermPosition],phraseWord);

        if ( strcmp(fileWord, phraseWord ) == 0 ) {
            if ( searchTermPosition == phrase.size()-1 ) {
                numberOfOccurences += 1;
                searchTermPosition = 0;
            } else {
                searchTermPosition += 1;
            }
        } else {
            searchTermPosition = 0;
        }
    }
    file.close();
    return numberOfOccurences;
}

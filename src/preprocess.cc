#include "preprocess.h"

Preprocess::Preprocess(string searchTerm) {
    Preprocess::searchTerm = searchTerm;
    SplitSearchTerm(searchTerm);

    map<string, int> frenchMap;
    map<string, int> hitchMap;
    map<string, int> warpMap;

    fileToProcessedWordsMap.insert(pair<string, map<string, int>>("french_armed_forces.txt", frenchMap));
    fileToProcessedWordsMap.insert(pair<string, map<string, int>>("hitchhikers.txt", hitchMap));
    fileToProcessedWordsMap.insert(pair<string, map<string, int>>("warp_drive.txt", warpMap));

    for (int i = 0; i < 3; i++) {
        StoreWordsInMap(fileNames[i]);
    }
}

int Preprocess::FindMatches(string fileName) {
    return (fileToProcessedWordsMap[fileName])[searchTerm];
}

void Preprocess::StoreWordsInMap(string fileName) {
    fileToProcessedWordsMap[fileName].insert(pair<string, int>(searchTerm, 0));
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error: This file could not open" << endl;
    }

    int searchTermPosition = 0;
    string singleWord;
    while(file >> singleWord) {
        if (fileToProcessedWordsMap[fileName].count(singleWord) > 0) {
            fileToProcessedWordsMap[fileName][singleWord] += 1;
        } else {
            fileToProcessedWordsMap[fileName].insert(pair<string, int>(singleWord, 1));
        }

        if (phrase.size() > 1) {
            int size1 = singleWord.length();
            int size2 = phrase[searchTermPosition].length();
            char fileWord[size1+1];
            char phraseWord[size2+1];

            StringToCharacterPtr(singleWord,fileWord);
            StringToCharacterPtr(phrase[searchTermPosition],phraseWord);

            if (strcmp(fileWord, phraseWord) == 0) {
                if (searchTermPosition == phrase.size()-1) {
                    fileToProcessedWordsMap[fileName][searchTerm] += 1;
                    searchTermPosition = 0;
                } else {
                    searchTermPosition += 1;
                }
            } else {
                searchTermPosition = 0;
            }
        }
    }
    file.close();
}

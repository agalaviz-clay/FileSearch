#include "preprocess.h"

Preprocess::Preprocess(string searchTerm) {
    searchTerm_ = searchTerm;
    SplitSearchTerm(searchTerm_);
    vector<string> fileNames;

    fileNames.push_back("data/french_armed_forces.txt");
    fileNames.push_back("data/hitchhikers.txt");
    fileNames.push_back("data/warp_drive.txt");

    map<string, int> frenchMap;
    map<string, int> hitchMap;
    map<string, int> warpMap;

    maps.insert(pair<string, map<string, int>>("french_armed_forces.txt", frenchMap));
    maps.insert(pair<string, map<string, int>>("hitchhikers.txt", hitchMap));
    maps.insert(pair<string, map<string, int>>("warp_drive.txt",warpMap));

    for (int i = 0; i < 3; i++) {
        StoreWordsInMap(fileNames[i]);
    }
}

int Preprocess::FindMatches(string fileName) {
    return (maps[fileName])[searchTerm_];
}

void Preprocess::StoreWordsInMap(string fileName) {
    maps[fileName].insert(pair<string, int>(searchTerm_, 0));
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "error: couldn't open up the file" << endl;
    }

    int searchTermPosition = 0;
    string singleWord;
    while(file >> singleWord) {
        if (maps[fileName].count(singleWord) > 0) {
            maps[fileName][singleWord] += 1;
        } else {
            maps[fileName].insert(pair<string, int>(singleWord, 1));
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
                    maps[fileName][searchTerm_] += 1;
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

#include "search.h"

Search::Search() {}

void Search::StringToCharacterPtr(string str, char *ptr) {
    strcpy(ptr, str.c_str());
}

void Search::SplitSearchTerm(string searchTerm) {
    char delim[] = " ";
    int n = searchTerm.length();
    char char_array[n+1];
    strcpy(char_array, searchTerm.c_str());
    char *singleWord = strtok(char_array,delim);
    while (singleWord) {
        phrase.push_back(singleWord);
        singleWord = strtok(NULL, delim);
    }
}

void Search::StoreMatchesFound() {
    for (int i = 0; i < 3; i++) {
        int num = FindMatches(fileNames[i]);
        get<0>(fileInfo[i]) = num;
    }
}

void Search::SortByRelevancy() {
    sort(fileInfo.begin(), fileInfo.end());
}

void Search::DisplayResults() {
    cout << "Search results:" << endl;
    for (int i = fileInfo.size()-1; i >= 0; i--) {
        cout << "    " << get<1>(fileInfo[i]) << " - " << get<0>(fileInfo[i]) << " matches"<< std::endl;
    }
}

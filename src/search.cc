#include "search.h"

Search::Search() {
    fileInfo.push_back( tuple<int,string>(0, "french_armed_forces.txt"));
    fileInfo.push_back( tuple<int,string>(0, "hitchhikers.txt"));
    fileInfo.push_back( tuple<int,string>(0, "warp_drive.txt"));
}

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
    vector<string> fileNames;
    fileNames.push_back("french_armed_forces.txt");
    fileNames.push_back("hitchhikers.txt");
    fileNames.push_back("warp_drive.txt");

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
        cout << "    " << get<1>(fileInfo[i]) << "-" << get<0>(fileInfo[i])
             << " matches"<< std::endl;
    }
}

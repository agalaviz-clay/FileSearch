#ifndef SEARCH_H_
#define SEARCH_H_
#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>  // used for the sort() function

using namespace std;

class Search {
    public:
        Search();
        void StringToCharacterPtr(string str, char *ptr);
        virtual int FindMatches(string fileName) = 0;
        void DisplayResults();
        void SplitSearchTerm(string searchTerm);
        void StoreMatchesFound();
        void SortByRelevancy();

    protected:
        vector<string> phrase;
        vector<tuple<int,string>> fileInfo = {{0, "french_armed_forces.txt"}, {0, "hitchhikers.txt"}, {0, "warp_drive.txt"}};
        vector<string> fileNames = {"../data/french_armed_forces.txt", "../data/hitchhikers.txt", "../data/warp_drive.txt"};
};
#endif

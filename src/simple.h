#ifndef SIMPLE_H_
#define SIMPLE_H_
#include <iostream>
#include <map>
#include <string.h>
#include <bits/stdc++.h>  // used for the sort() function
#include "search.h"
using namespace std;

class Simple : public Search {
    public:
        Simple(string searchTerm);
        int FindMatches(string fileName);
};
#endif

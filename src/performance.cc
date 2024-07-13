#include "search.h"
#include "simple.h"
#include "regular.h"
#include "preprocess.h"
#include <chrono>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

// This is a very naive approach to testing the performance of all 3 searches!

string RandomWordGenerator(int length) {
	static string characterOptions = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~`!@#$^&*()-_=+[]{};:'<,.>/?";
	string result;
	result.resize(length);
	for (int i = 0; i < length; i++) {
		result[i] = characterOptions[rand() % characterOptions.length()];
	}
	return result;
}

int main() {
    srand(time(NULL));
    string searchTerm = RandomWordGenerator(5);

    // Regular Expression Search
    Regular reg(searchTerm);
    auto start3 = high_resolution_clock::now();
    for (int i = 1; i < 2000000; i++) {{}
	    reg.StoreMatchesFound();
    }
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(stop3 - start3);
    cout << "Elapsed Time for regular expression: " << duration3.count() << "ms" << endl;

    // Index Search
    Preprocess index(searchTerm);
    auto start1 = high_resolution_clock::now();
    for (int i = 1; i < 2000000; i++) {
	    index.StoreMatchesFound();
	}
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Elapsed Time for index: " << duration1.count() << "ms" << endl;

    // String Match Search
    Simple simple(searchTerm);
    auto start2 = high_resolution_clock::now();
    for (int i = 1; i < 2000000; i++) {
	    simple.StoreMatchesFound();
	}
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Elapsed Time for string match: " << duration2.count() << "ms" << endl;

    return 0;
}

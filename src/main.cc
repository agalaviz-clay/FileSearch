#include "search.h"
#include "simple.h"
#include "regex.h"
#include "preprocess.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    string searchTerm;
    int searchMethod;
    cout << "Enter the seach term: " << endl;
    getline(cin,searchTerm);
    cout << "Enter 1 for String Match, 2 for Regular Expression, 3 for Indexed: " << endl;
    cin >> searchMethod;

    if (searchMethod == 1) {
        Simple simple(searchTerm);
        // Keep track of speed in ms
        auto start = high_resolution_clock::now();

        // Store all the number of matches found for each file in an unsorted vector
        simple.StoreMatchesFound();

        // Gets the time the above algorithm finished
        auto stop = high_resolution_clock::now();
        simple.SortByRelevancy();
        simple.DisplayResults();

        // Gets the time in ms of the String Match algorithm
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Elapsed Time: " << duration.count() << "ms" << endl;
        return 0;
    } else if (searchMethod == 2) {
        Regex reg(searchTerm);
        auto start = high_resolution_clock::now();

        reg.StoreMatchesFound();

        auto stop = high_resolution_clock::now();

        reg.SortByRelevancy();
        reg.DisplayResults();

        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Elapsed Time: " << duration.count() << "ms" << endl;
        return 0;
    } else if (searchMethod == 3) {
        Preprocess index(searchTerm);
        auto start = high_resolution_clock::now();

        index.StoreMatchesFound();

        auto stop = high_resolution_clock::now();

        index.SortByRelevancy();
        index.DisplayResults();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Elapsed Time: " << duration.count() << "ms" << endl;
        return 0;
    } else {
        cout << "Invalid option, rerun and try again." << endl;
        return 0;
    }
}

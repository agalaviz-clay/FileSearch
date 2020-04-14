#include "search.h"
#include "simple.h"
#include "regular.h"
#include "preprocess.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
  string searchTerm;
  int searchMethod;
  cout << "Enter the seach term:" << endl;
  getline(cin,searchTerm);
  cout << "Enter 1 for String Match, 2 for Regular Expression,3 for Indexed"
          << endl;
  cin >> searchMethod;

  if (searchMethod == 1) {
    Simple simple(searchTerm);
    // created to keep track of speed in ms
    auto start = high_resolution_clock::now();

    // store all the number of matches found for each file in an unsorted vector
    simple.StoreMatchesFound();

    // gets me the time the above algorithm finished.
    auto stop = high_resolution_clock::now();
    simple.SortByRelevancy();
    simple.DisplayResults();

    // gets me the time in ms of the algorith of string match
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Elapsed Time: " << duration.count() << "ms" << endl;
    return 0;
  } else if (searchMethod == 2) {
      Regular reg(searchTerm);
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
    // error
    cout << "Invalid option, rerun and try again." << endl;
    return 0;
  }
}

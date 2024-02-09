#include <iostream>
#include <vector>
#include <random>

using namespace std;
using namespace chrono;

vector<int> generateRandomVector(int length, int minVal, int maxVal) {
    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(minVal, maxVal);

    // Generate the random vector
    vector<int> randomVector(length);
    for (int i = 0; i < length; ++i) {
        randomVector[i] = distribution(gen);
    }

    return randomVector;
}


void YOUR_ITERATIVE_MERGE_SORT (vector<int> arr){

    /*
     * ENTER YOUR ITERATIVE MERGE SORT HERE. CAL ANY OTHER FUNCTIONS IF YOU NEED
     */

}

vector<int> YOUR_RECURSIVE_MERGE_SORT(vector<int> arr){

    /*
     * ENTER YOUR RECURSIVE MERGE SORT HERE. CAL ANY OTHER FUNCTIONS IF YOU NEED
     */

}

void recursiveMergeSort(vector<int> arr){
    YOUR_RECURSIVE_MERGE_SORT(arr);
}



int main() {
    int upperLimit = 50;
    int lowerLimit = 3;
    int skips = 2;
    int listLow = 0;
    int listHigh = 500;

    vector<int> testList;

    void (*algorithms[])(vector<int>) = {recursiveMergeSort, YOUR_ITERATIVE_MERGE_SORT};
    int funcsLen = 2;
    string names[] = {"Recursive Merge Sort", "Iterative Merge Sort"};

    for(int length = lowerLimit; length <= upperLimit; length = length + skips){
        //COMMENT OUT THIS ONE IF YOU WANT. IT JUST SHOWS YOU
        cout << "For a list of " << length << " elements, " <<endl;
        for(int i = 0; i < funcsLen; i++) {
            duration<double> duration[5];
            for (int x = 0; x < 5; x++) {
                testList = generateRandomVector(length, listLow, listHigh);
                auto start = high_resolution_clock::now();
                algorithms[i](testList);
                auto end = high_resolution_clock::now();
                duration[x] = end - start;
            }
            ::duration<double> finalDur = (duration[0] + duration[1] + duration[2] + duration[3] + duration[4])/5;

            /*
             * THIS ONE WILL GIVE YOU THE EXECUTION TIMES OF THE RECURSIVE MERGE SORT AND ITERATIVE MERGE
             * SORT RESPECTIVELY IN MICROSECONDS.
             */
            cout  << finalDur.count()*1000000   << endl;
        }

    }
    return 0;
}

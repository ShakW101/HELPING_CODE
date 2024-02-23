/*
    Special thanks to Erandathee
*/

#include <iostream>
#include <vector>
#include <random>
#import <fstream>

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

//ENTER CODE FOR YOUR SORTING ALGORITHMS HERE
void ALGORITHM1 (vector<int> arr){

}

void ALGORITHM2 (vector<int> arr){

}

void ALGORITHM3 (vector<int> arr){

}

int main() {

    string title = "ENTER TITLE HERE";
    string xAxis = "ENTER X-AXIS LABEL HERE";
    string yAxis = "ENTER Y-AXIS LABEL HERE";

    //ENTER MAX SIZE OF LIST, MIN SIZE OF LIST, INCREMENTS IN SIZE, BOUND FOR SMALLEST NUMBER, BIGGEST NUMBER IN LIST
    int upperLimit = 50;
    int lowerLimit = 3;
    int skips = 2;
    int listLow = 0;
    int listHigh = 500;

    //ENTER NUMBER OF ALGORITHMS TO CHECK TIME ON
    int funcsLen = 3;

    vector<int> testList;
    vector<double> times[funcsLen];

    ofstream datafile[funcsLen];
    string finalPlots = "plot ";

    //ENTER NAMES OF SORTING ALGORITHMS
    string names[] = {"ALGORITHM 1", "ALGORITHM 2", "ALGORITHM 3"};

    //ENTER FUNCTIONS TO CALL SORTING ALGORITHMS
    void (*algorithms[])(vector<int>) = {ALGORITHM1, ALGORITHM2, ALGORITHM3};

    string namesWithoutSpaces[funcsLen];

    for(int i = 0; i < funcsLen; i++) {
        string str = names[i];
        str.erase(remove(str.begin(), str.end(), ' '));
        namesWithoutSpaces[i] = str;
        datafile[i].open(namesWithoutSpaces[i]+".txt");
        datafile[i] << "# Input Size Time(µs)" << endl;
    }

    for(int length = lowerLimit; length <= upperLimit; length = length + skips){
        //COMMENT OUT THIS ONE IF YOU WANT. IT JUST SHOWS YOU
        cout << "For a list of " << length << " elements, " <<endl;
        for(int i = 0; i < funcsLen; i++) {
            duration<double> duration[5];

            for(int x = 0; x < 5; x++) {
                testList = generateRandomVector(length, listLow, listHigh);
                auto start = high_resolution_clock::now();
                algorithms[i](testList);
                auto end = high_resolution_clock::now();
                duration[x] = end - start;
            }

            ::duration<double> finalDur = (duration[0] + duration[1] + duration[2] + duration[3] + duration[4])/5;

            //time in microseconds
            double time = finalDur.count()*1000000;
            times[i].push_back(time);
            cout << names[i] <<" took "<<time<<" µs."<<endl;
            datafile[i] << length << " " << time <<endl;
        }
        cout<<endl;
    }

    for(int i = 0; i < funcsLen ; i ++){
        datafile[i].close();
        finalPlots += "'"+namesWithoutSpaces[i]+".txt' with linespoints title '"+names[i]+"'";
        if(i != funcsLen - 1){
            finalPlots +=", ";
        }else{
            finalPlots += "\n";
        }
    }

    title = "set title '"+title+"'\n";
    xAxis = "set xlabel '"+xAxis+"'\n";
    yAxis = "set ylabel '"+yAxis+"'\n";


    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "%s", title.c_str());
    fprintf(gnuplotPipe, "%s", xAxis.c_str());
    fprintf(gnuplotPipe, "%s", yAxis.c_str());
    fprintf(gnuplotPipe, "%s", finalPlots.c_str());
    fflush(gnuplotPipe);

    return 0;
}

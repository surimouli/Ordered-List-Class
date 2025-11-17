#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
using namespace std;

void RunTest(int arraySize, int numRuns) {
    cout << "Running test with array size: " << arraySize << "\n";

    long long totalCompFront = 0, totalMovesFront = 0;
    long long totalCompEnd = 0, totalMovesEnd = 0;
    long long totalCompGap = 0, totalMovesGap = 0;

    for (int run = 1; run <= numRuns; run++) {
        OrderedList<int> listFront(arraySize);
        EndOrderedList<int> listEnd(arraySize);
        GapOrderedList<int> listGap(arraySize);


        vector<int> insertedValues;
        for (int i = 0; i < 30; i++) {
            int value = rand() % 100;
            insertedValues.push_back(value);
            try {
                listFront.AddItem(value);
                listEnd.AddItem(value);
                listGap.AddItem(value);
            } 
            catch (const ListError& e) {
                break;
            }
        }

        for (int i = 0; i < 25 && !insertedValues.empty(); i++) 
        {
            int index = rand() % insertedValues.size();
            int valueToRemove = insertedValues[index];
            try {
                listFront.RemoveItem(valueToRemove);
                listEnd.RemoveItem(valueToRemove);
                listGap.RemoveItem(valueToRemove);
            } catch (const ListError& e) {}

            insertedValues.erase(insertedValues.begin() + index);
        }

        totalCompFront += listFront.comparisons;
        totalMovesFront += listFront.moves;
        totalCompEnd += listEnd.comparisons;
        totalMovesEnd += listEnd.moves;
        totalCompGap += listGap.comparisons;
        totalMovesGap += listGap.moves;

        if (run == numRuns) {
            cout << "\nFinal List Contents after run " << run << ":";

            cout << "\nTask 1 - Front Insert: ";
            listFront.PrintContents();
            cout << "Size: " << listFront.Size() << " / " << arraySize << "\n";

            cout << "\nTask 2 - End Insert: ";
            listEnd.PrintContents();
            cout << "Size: " << listEnd.Size() << " / " << arraySize << "\n";

            cout << "\nTask 3 - Gap Insert: ";
            listGap.PrintContentsWithGaps();
            cout << "Size: " << listGap.Size() << " / " << arraySize << "\n";
        }
    }
    cout << "\nAverage Comparisons and Moves over " << numRuns << " runs:\n";
    cout << "Task1 Front Insert - Avg Comparisons: " << totalCompFront / numRuns
         << ", Avg Moves: " << totalMovesFront / numRuns << "\n";
    cout << "Task2 End Insert - Avg Comparisons: " << totalCompEnd / numRuns
         << ", Avg Moves: " << totalMovesEnd / numRuns << "\n";
    cout << "Task3 Gap Insert - Avg Comparisons: " << totalCompGap / numRuns
         << ", Avg Moves: " << totalMovesGap / numRuns << "\n\n\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    vector<int> sizes = {20, 50, 10};
    int numRuns = 100;

    for (int size : sizes) {
        RunTest(size, numRuns);
    }

    return 0;
}
/*
 Given a 2D array A[1,n][1,n] of n2 numbers such that, in each row (from left to right) 
 as well as in each column (from top to bottom), the elements are in the sorted order. 
 Design an O(n) time algorithm to check if A contains a given number "x". Also, prove 
 that it is not possible to design an o(n) time algorithm [i.e., a lower bound].
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"

using namespace std;

// Basic idea is to find the correct row, then correct column.
// Since rows and cols are sorted, we can first find the correct 
// row by comparing the final elements in each row to the target.
// Based on the comparison, we know whether to eliminate that row 
// or keep it. We can do the same for columns, allowing us to 
// significantly reduce the search space across both axes.
void grid_search(vector<vector<int>> input, int target) {
    int i = 0;
    int j = input.size() - 1;
    int step_count = 0;

    while (i < input.size() && j >= 0) {
        // track number of steps taken to find target 4fun
        step_count++;

        // if we've found the target, end
        if (target == input[i][j]) {
            cout << "Found target at (" << i << ", " << j << "); ";
            cout << "Steps taken: " << step_count << endl;
            return;
        } else if (target > input[i][j]) {
            // the target can't be in the current row, and 
            // can't be above the current element in its column 
            // so eliminate both
            i++;
        } else {
            // the target can't be in any lower rows or any 
            // more rightward cols; reflect that change here
            j--;
        }
    }

    cout << "Target not found. Steps taken: " << step_count << endl;
    return;
}

int main() {

    vector<vector<int>> test
    {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    for (int i = 0; i < test.size(); i++) {
        for (int j = 0; j < test[i].size(); j++) {
            grid_search(test, test[i][j]);
        }
        
    }

    // print_vector(test);

    return 0;
}
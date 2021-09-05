#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> input) {
    int total = 0;

    for (int i = 0; i < input.size(); i++) {
        total += input[i];
    }

    return total;
}

void brute_force(vector<int> x, vector<int> y) {
    int sum_x = sum(x);
    int sum_y = sum(y);
    int tempsum_x, tempsum_y = 0;

    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < y.size(); j++) {
            tempsum_x = sum_x - x[i] + y[j];
            tempsum_y = sum_y - y[j] + x[i];

            if (tempsum_x == tempsum_y) {
                cout << "Found matching sum: swap x[" << i << "] and y[" << j << "]." << endl;
                cout << "new matching sum: " << tempsum_x << endl;
                return;
            }
        }
    }

    cout << "No matching sum found." << endl;
}

int main() {

    // no sum found case
    // vector<int> x = {1, 4, 5, 7, 9}; // sum = 26
    // vector<int> y = {5, 3, 5, 7, 13}; // sum = 33

    // sum found case
    vector<int> x = {1, 3, 5, 7, 9}; // sum = 24
    vector<int> y = {3, 3, 7, 7, 13}; // sum = 32

    // difference: 8, so we want to find 2 nums that differ by  
    // 8 / 2 => 4

    cout << "x initial sum: " << sum(x) << endl;
    cout << "y initial sum: " << sum(y) << endl;

    brute_force(x, y);

    return 0;
}
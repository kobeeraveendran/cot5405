#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

void array_diff(vector<int> x, vector<int> y) {
    int target_diff = sum(x) - sum(y);
    
    if (target_diff % 2 != 0) {
        cout << "No matching sum found." << endl;
        return;
    }

    target_diff /= 2;
    cout << "target diff: " << target_diff << endl;
    unordered_map<int, int> diff_map;

    for (int i = 0; i < x.size(); i++) {
        diff_map[x[i]] = i;
    }

    for (int i = 0; i < y.size(); i++) {
        if (diff_map.find(target_diff + y[i]) != diff_map.end()) {
            int index = diff_map[target_diff + y[i]];
            cout << "Found matching sum: swap x[" << index << "]  and y[" << i << "]." << endl;
            int temp = x[index];
            x[index] = y[i];
            y[i] = temp;

            cout << "new x sum: " << sum(x) << endl;
            cout << "new y sum: " << sum(y) << endl;
            return;
        }
    }
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
    cout << endl;
    array_diff(x, y);

    return 0;
}
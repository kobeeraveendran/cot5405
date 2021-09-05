#include <iostream>
#include <vector>

using namespace std;

void PrintArray(int array[], int array_size) {
    std::cout << '[';

    for (int i = 0; i < array_size; i++) {
        std::cout << array[i];

        if (i != array_size - 1) {
            std::cout << ", ";
        }
    }

    std::cout << ']' << std::endl;
}

void print_vector(vector<vector<int>> input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << '\t';
        }
        cout << endl;
    }
}

void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}
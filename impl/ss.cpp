// selection sort implementation

#include <iostream>
#include "utils.h"

void SelectionSort(int array[], int array_size) {
    int temp;

    for (int i = 0; i < array_size - 1; i++ ){
        for (int j = i + 1; j < array_size; j++) {
            if (array[j] < array[i]) {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main() {
    int test1[5] = {1, 4, 2, 6, 89};
    int test1_size = sizeof(test1) / sizeof(test1[0]);

    std::cout << "unsorted: ";
    PrintArray(test1, test1_size);
    SelectionSort(test1, test1_size);
    std::cout << "  sorted: ";
    PrintArray(test1, test1_size);

    return 0;
}
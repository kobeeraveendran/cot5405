// quicksort implementation

#include <iostream>
#include "utils.h"

int partition(int array[], int low, int high) {

    int pivot = low;
    int index = high - 1;

    for (int i = low; i < high; i++) {
        if (array[i] < array[pivot]) {
            pivot++;
            swap(array, low, pivot);
            swap(array, high - 1, i);
        }
    }

    return index;
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

int main() {

    int test[] = {5, 3, 20, 1, 9};
    int test_size = sizeof(test) / sizeof(test[0]);

    std::cout << "pre-partition : ";
    PrintArray(test, test_size);
    std::cout << "post-partition: ";
    partition(test, 0, test_size);
    PrintArray(test, test_size);

    return 0;
}
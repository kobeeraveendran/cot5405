#include <iostream>
#include <algorithm>
#include "utils.h"

using namespace std;

void k_sort(int input[], int length) {

    sort(0, length - 1);

    cout << "sorted: ";
    PrintArray(input, length);

}

int main() {

    int test[] = {10, 11, 9, 12, 1, 3, 2, 4, 15, 13, 16, 14, 6, 7, 5};
    int test_length = sizeof(test) / sizeof(test[0]);

    k_sort(test, test_length);

    return 0;
}
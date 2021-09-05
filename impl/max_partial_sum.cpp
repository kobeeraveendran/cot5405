/*
 Define maximum partial sum problem (MPS) as follows. Given an array A[1,n] of integers, 
 and values of i and j with 1≤i ≤j≤n such that A[i]+A[i+1]+A[i+2]+...+A[j] is maximized. 
 For example, for the array [3,-5,6,7,8,-10,7], the solution to MPS is i = 3 and j = 5 
 (sum is 21). Design an O(n log n) time algorithm. [Hint: Divide and Conquer approach]. 
 Can you improve the time complexity to O(n)?
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void mps(int input[], int length) {
    int j, k, final_j, final_k = 0;
    int total_max = INT_MIN;
    int curr_max = 0;

    for (int i = 0; i < length; i++) {

        if (input[i] > curr_max + input[i]) {
            // start the subarray here
            j = i;
            k = i + 1;
            curr_max = input[i];
        } else {
            // continue the previous subarray and "absorb" this element into it
            k = i;
            curr_max += input[i];
        }

        if (curr_max > total_max) {
            final_j = j;
            final_k = k;
            total_max = curr_max;
        }
    }

    cout << "maximum partial sum: " << total_max << endl;
    cout << "MPS indices: j = " << final_j << "; k = " << final_k << ";" << endl;
}

int main() {

    int test[] = {3,-5,6,7,8,-10,7};

    mps(test, sizeof(test) / sizeof(test[0]));

    return 0;
}
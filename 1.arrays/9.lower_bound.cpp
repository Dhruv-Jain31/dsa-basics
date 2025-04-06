/*Given an array of integers A (sorted) and a integer Val.

Implement a function that takes A and Val as input parameters and returns the lower bound of Val.

Note : If Val is not present in array then Lower bound of a given integer means integer which is just smaller than given integer.

Otherwise Val itself is the answer.

If Val is less than smallest element of array A then return '-1' in that case.*/

#include <iostream>
#include <vector>

using namespace std;

int lowerBound_linear_search(vector<int> A, int Val) {
    // your code goes here
    int ans = -1;
    for(auto x : A){
        if(x == Val){
            return Val;
        }
        if(x < Val){
            ans = x;
        }
        else{
            break;
        }
    }
    return ans;
}

int lowerBound_binary_search(vector<int>A, int Val) {
    int left = 0, right = A.size() - 1;
    int ans = -1;

    while(left<=right){
        int mid = left + (right - left)/2;
        if(A[mid] == Val){
            return Val;
        }
        if(A[mid] <= Val){
            ans = A[mid]; //update the answer and look for the bigger number which is less than or equal to val
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 3, 5, 7, 9, 11};
    cout << "Lower Bound: " << lowerBound_binary_search(A, 6) << endl;  // Expected: 5
    cout << "Lower Bound: " << lowerBound_binary_search(A, 3) << endl;  // Expected: 3
    cout << "Lower Bound: " << lowerBound_binary_search(A, 0) << endl;  // Expected: -1
    return 0;
}
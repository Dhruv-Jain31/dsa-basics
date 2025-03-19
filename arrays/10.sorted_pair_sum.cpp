/*Sorted Pair Sum
Given a sorted array and a number x, find a pair in array whose sum is closest to x.

Input Format

In the function an integer vector and number x is passed.

Output Format

Return a pair of integers.



Sample Input

{10, 22, 28, 29, 30, 40}, x = 54


Sample Output

22 and 30
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    // your code goes here
    int start = 0; int end = arr.size() - 1;
    int diff = INT_MAX;
    int left_index, right_index;

    for(int i = 0; i < arr.size(); i++){
        int sum = arr[start] + arr[end];
        if(abs(sum - x) < diff){
            diff = abs(sum - x);
            left_index = start;
            right_index = end;
        }
        if(sum > x){
            end -= 1;
        }
        if(sum < x){
            start += 1;
        }
        if(start == end || end < start){
            break;
        }
    }
    return {arr[left_index],arr[right_index]};
}

int main() {
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    int x = 54;

    pair<int, int> result = closestSum(arr, x);
    cout << "Closest Pair Sum: " << result.first << " and " << result.second << endl;

    return 0;
}
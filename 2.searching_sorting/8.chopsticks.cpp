/*Chopsticks
Given N sticks and an array length where each length[i] represents length of each stick. Your task is to make maximum number of pairs of these sticks such that the difference between the length of two sticks is at most D. A stick can't be part of more than one pair of sticks.

Input Format

In the function an integer vector length and number D is passed.

Output Format

Return an integer representing total number of such pairs.



Sample Input

{1, 3, 3, 9, 4}, x = 2


Sample Output

2


Explanation

(1st, 3rd) and (2nd, 5th) can be paired together.*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> insertion_sort(vector<int> length){
    //length.size() returns a value of type std::vector<int>::size_type,
    //which is an unsigned integer (typically size_t). so we change the type of i from int to size_t
    for(size_t i = 1; i <= length.size() - 1; i++){
        int current = length[i];
        int prev = i-1;
        while(prev >= 0 && length[prev] > current){
            length[prev + 1] = length[prev];
            prev--;
        }
        length[prev + 1] = current;
    }
    return length;
}

int pairSticks(vector<int> length, int D)
{
    // your code goes here
    int count = 0;
    vector<pair<int, int>> pairs;
    vector<int> sorted_length = insertion_sort(length);
    for(int i = 0; i<sorted_length.size();i++){
        for(int j = i+1; j< sorted_length.size(); j++){
            if(sorted_length[j] - sorted_length[i] == D){
                count++;
                pairs.push_back({sorted_length[j], sorted_length[i]});
            }
        }
    }
    for(auto p: pairs){
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }
    return count;
}

int main() {
    // Sample test case
    vector<int> length = {4,6,1,3,9,2,5}; // Stick lengths
    int D = 2; // Maximum allowed difference

    // Call the pairSticks function and output the result
    int result = pairSticks(length, D);
    cout << "Maximum number of pairs: " << result << endl;

    return 0;
}
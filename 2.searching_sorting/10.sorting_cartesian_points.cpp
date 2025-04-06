/*Sorting Cartesian Points
Given co-ordinates of N points on X-Y axis, your task is to sort them in accordance to the x-coordinate. 
If the x-coordinates are same then compare y-coordinates.

Input Format

In the function an integer vector of pairs is passed.

Output Format

Return the vector in sorted order.



Sample Input

{ (3, 4), (2, 3), (3, 7), (1, 5), (3, 4) }


Sample Output

{ (1, 5), (2, 3), (3, 4), (3, 4), (3, 7) } */

// we are using modifed selection in it

#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();

    for(int pos = 0; pos < N-2; pos++){
        int min_position = pos;

        for(int j = 0; j < N; j++){
            if(v[j].first < v[min_position].first){
                min_position = j;
            }
            else if(v[j].first == v[min_position].first && v[j].second < v[min_position].second){
                min_position = j;
            }
        }
        swap(v[min_position],v[pos]);
    }
    return v;
}

// Driver Code
int main() {
    vector<pair<int, int>> points = {{3,4},{2,3},{3,7},{1,5},{3,4}};

    vector<pair<int, int>> sorted_points = sortCartesian(points);

    for (auto p : sorted_points) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
/*Submatrix Sum
Given a matrix of size M x N, there are large number of queries to find submatrix sums.
Inputs to queries are left top and right bottom indexes of submatrix whose sum is to find out.

How to preprocess the matrix so that submatrix sum queries can be performed in O(1) time.



INPUT FORMAT:

Given a matrix (2d vector) and query.. Each query has Starting row, Starting column, Ending row, Ending column.



OUTPUT FORMAT:

A single integer which is the sum of the submatrix.


Example :

tli :  Row number of top left of query submatrix
tlj :  Column number of top left of query submatrix
rbi :  Row number of bottom right of query submatrix
rbj :  Column number of bottom right of query submatrix
 
Input: mat[M][N] = {{1, 2, 3, 4, 6},
                    {5, 3, 8, 1, 2},
                    {4, 6, 7, 5, 5},
                    {2, 4, 8, 9, 4} };
Query1: tli = 0, tlj = 0, rbi = 1, rbj = 1
Query2: tli = 2, tlj = 2, rbi = 3, rbj = 4
Query3: tli = 1, tlj = 2, rbi = 3, rbj = 3;
 
Output:
Query1: 11  // Sum between (0, 0) and (1, 1)
Query2: 38  // Sum between (2, 2) and (3, 4)
Query3: 38  // Sum between (1, 2) and (3, 3)*/

#include <iostream>
#include<vector>
using namespace std;

// Compute prefix inside this function (since we can't pass it)
int sum(vector<vector<int>> v, int sr, int sc, int er, int ec) {
    int m = v.size();
    int n = v[0].size();

    vector<vector<int>> prefix(m, vector<int>(n));
    prefix[0][0] = v[0][0];

    // Fill first column
    for (int i = 1; i < m; i++) {
        prefix[i][0] = prefix[i - 1][0] + v[i][0];
    }

    // Fill first row
    for (int j = 1; j < n; j++) {
        prefix[0][j] = prefix[0][j - 1] + v[0][j];
    }

    // Fill the rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            prefix[i][j] = v[i][j]
                         + prefix[i - 1][j]
                         + prefix[i][j - 1]
                         - prefix[i - 1][j - 1];
        }
    }

    // Now calculate sum of submatrix from (sr, sc) to (er, ec)
    int res = prefix[er][ec];
    if (sr > 0) res -= prefix[sr - 1][ec];
    if (sc > 0) res -= prefix[er][sc - 1];
    if (sr > 0 && sc > 0) res += prefix[sr - 1][sc - 1];

    return res;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4, 6},
        {5, 3, 8, 1, 2},
        {4, 6, 7, 5, 5},
        {2, 4, 8, 9, 4}
    };

    cout << "Query1: " << sum(mat, 0, 0, 1, 1) << endl; // 11
    cout << "Query2: " << sum(mat, 2, 2, 3, 4) << endl; // 38
    cout << "Query3: " << sum(mat, 1, 2, 3, 3) << endl; // 38

    return 0;
}

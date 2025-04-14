/*Ramu's father has left a farm organized as an N × N grid. Each square in the grid either has or does not have a mango tree. 
He has to divide the farm with his three sisters as follows: he will draw one horizontal line and one vertical line to divide the field into four rectangles. 
His sisters will choose three of the four smaller fields and he gets the last one.

He wants to divide the field so that he gets the maximum number of mangos possible,
 assuming that his sisters will pick the best three rectangles.

For example, suppose the field looks as follows:

      . # # . . .
      # . . # # .
      . # . . . .
      . # # . . #
      # . . # # .
      . # . . . .

Ramu can ensure that he gets at least 3 mango trees by cutting as follows:

        . # | # . . .
        # . | . # # .
        . # | . . . .
      ------+---------
        . # | # . . #
        # . | . # # .
        . # | . . . .
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get sum of mangoes in any sub-rectangle
int getPrefixSum(const vector<vector<int>>& prefix, int x1, int y1, int x2, int y2) {
    int total = prefix[x2][y2];
    if (x1 > 0) total -= prefix[x1 - 1][y2];
    if (y1 > 0) total -= prefix[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) total += prefix[x1 - 1][y1 - 1];
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    // Read input and convert to 0/1 grid
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            grid[i][j] = (row[j] == '#') ? 1 : 0;
        }
    }

    // Step 1: Build prefix sum matrix
    vector<vector<int>> prefix(n, vector<int>(n, 0));
    prefix[0][0] = grid[0][0];

    // First row and column
    for (int i = 1; i < n; i++) {
        prefix[i][0] = prefix[i - 1][0] + grid[i][0];
        prefix[0][i] = prefix[0][i - 1] + grid[0][i];
    }

    // Rest of the grid
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            prefix[i][j] = grid[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    // Step 2: Try all possible cuts
    int maxMangoes = 0;
    for (int x = 0; x < n - 1; x++) {
        for (int y = 0; y < n - 1; y++) {
            int r1 = getPrefixSum(prefix, 0, 0, x, y);
            int r2 = getPrefixSum(prefix, 0, y + 1, x, n - 1);
            int r3 = getPrefixSum(prefix, x + 1, 0, n - 1, y);
            int r4 = getPrefixSum(prefix, x + 1, y + 1, n - 1, n - 1);

            vector<int> parts = {r1, r2, r3, r4};
            sort(parts.begin(), parts.end());
            //parts[0] is the min among the 4 and ramu's sister get the best rectangles
            maxMangoes = max(maxMangoes, parts[0]);
        }
    }

    cout << maxMangoes << endl;
    return 0;
}





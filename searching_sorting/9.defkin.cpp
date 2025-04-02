/*Defense Kingdom
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells.
The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column.
No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.


Your task is to find the penalty of the give position.

Input Format

In the function an width and height of the kingdom and a vector of pairs representing positions of towers is passed.

Output Format

Return an integer representing the number of cells in the largest rectangle that is not defended by the towers.



Sample Input

15 8
{(3, 8), (11, 2), (8, 6)}


Sample Output

12*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here
    vector<int> width, height;
    int max_width = 0;
    int max_height = 0;
    width.push_back(0);
    height.push_back(0);
    
    for(auto i: position){
        width.push_back(i.first);
        height.push_back(i.second);
    }
    width.push_back(W+1);
    height.push_back(H+1);
    
    sort(width.begin(),width.end());
    sort(height.begin(),height.end());
    
    for(size_t i = 0; i<width.size()-1; i++){
        max_width = max(max_width,(width[i+1] - width[i]) - 1);
        max_height = max(max_height,(height[i+1] - height[i]) - 1);
    }
    return max_width * max_height;
}

int main() {
    int W, H, N; // N:no. of towers
    cin >> W >> H >> N;

    vector<pair<int, int>> towers(N);
    for (int i = 0; i < N; i++) {
        cin >> towers[i].first >> towers[i].second;
    }

    cout << defkin(W, H, towers) << endl;
    return 0;
}
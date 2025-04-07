/*Wave Print!
Given a matrix, print it in Reverse Wave Form.

Input Format:
Given integer m (number of rows), integer n (number of columns) and 2d vector.

Output Format:
Return a linear vector of integers in the required order.

Examples :

Input :
1 2 3 4

5 6 7 8

9 10 11 12

13 14 15 16

Output :
4 8 12 16 15 11 7 3 2 6 10 14 13 9 5 1


Input :
1 9 4 10

3 6 90 11

2 30 85 72

6 31 99 15

Output :
10 11 72 15 99 85 90 4 9 6 30 31 6 2 3 1

Note: This is an example for right to left wave also do it for left to right wave
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> R_L_WavePrint(int m, int n, vector<vector<int>> arr)
{
    vector<int> result;
    int start_col = 0;
    int end_col = n - 1;
    int start_row = 0;
    int end_row = m - 1;

    while(end_col >= start_col){
        for(int row = start_row; row <= end_row; row++){
            //cout << arr[row][end_col] << " ";
            result.push_back(arr[row][end_col]);
        }
        end_col --;

        for(int row = end_row; row>=start_row; row--){
            //cout << arr[row][end_col] << " ";
            result.push_back(arr[row][end_col]);
        }
        end_col --;
    }
    return result;
}

vector<int> L_R_WavePrint(int m, int n, vector<vector<int>> arr)
{
    vector<int> result;
    int start_col = 0;
    int end_col = n - 1;
    int start_row = 0;
    int end_row = m - 1;

    while(start_col <= end_col){
        for(int row = start_row; row <= end_row; row++){
            //cout << arr[row][end_col] << " ";
            result.push_back(arr[row][start_col]);
        }
        start_col ++;

        for(int row = end_row; row>=start_row; row--){
            //cout << arr[row][end_col] << " ";
            result.push_back(arr[row][start_col]);
        }
        start_col ++;
    }
    return result;

}

int main(){
    vector<vector<int>> arr ={{1,2,3,4},
                               {5,6,7,8},
                               {9,10,11,12},
                               {13,14,15,16}};

    int m = 4;
    int n = 4;
    vector<int> result = R_L_WavePrint(m,n,arr);
    vector<int> result2 = L_R_WavePrint(m,n,arr);

    cout << "LR Wave print" << endl;

    for(auto ch: result){
        cout << ch << " ";
    }

    cout << endl;
    cout << "RL Wave print" << endl;
    for(auto ch2: result2){
        cout<< ch2 << " ";
    }

    return 0;
}

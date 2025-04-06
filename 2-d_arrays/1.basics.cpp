#include<iostream>
using namespace std;

void print(int arr[][100], int n, int m){ //passing no. of rows is optional but no.of columns is mandatory
    //print
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[100][100]; //2d array of 100 rows and 100 columns
    int n,m;
    cin >> n >> m; //input no. of rows and columns

    //take input
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    //print the array
    print(arr,n,m);
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    cout << "comparing " << a << " and " << b << endl;
    return a > b;
}

int main(){
    int arr[] = {10,9,8,6,5,4,3,2,11,16,8};
    int n = sizeof(arr)/sizeof(int);

    //sort(arr, arr+n, greater<int>()); does the same work as the below function
    sort(arr, arr + n, compare); //this is not a fn call func is passed as a parameter to another function
    //reverse(arr, arr + n);

    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
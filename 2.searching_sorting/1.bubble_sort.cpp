#include <iostream>

using namespace std;

void bubble_sort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for (int j = 0; j < n - 1 - i; j++){
           if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
           }
        }
    }
}

int main(){
    int arr[] ={-2,3,4,-1,5,-12,6,1,8};
    int n = sizeof(arr)/sizeof(int);
    bubble_sort(arr,n);

    for(auto x : arr){
        cout << x << ",";
    }
}
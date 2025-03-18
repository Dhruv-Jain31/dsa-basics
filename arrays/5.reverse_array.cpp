#include <iostream>

using namespace std;

void reverseArray(int *arr, int n){
    int s = 0, e = n - 1;
    int temp;
    while (s < e){
        temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp; // or swap(arr[s], arr[e]);
        s = s+1;
        e = e-1;
    }
}

int main(){
    int arr[] = {10,20,30,45,60,80,90};
    int n = sizeof(arr)/sizeof(int);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArray(arr,n);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>

using namespace std;

int linear_search(int *arr, int n, int key){
    for (int i = 0; i < n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return -1; //out of loop
}

int main(){
    int arr[] = {12,34,31,25,32,45,78};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin >> key;

    int index = linear_search(arr,n,key);
    if(index != -1){
        cout << key << " is present at index " << index << endl;
    }
    else{
        cout << key << " is not found! " <<endl;
    }
    return 0;
}
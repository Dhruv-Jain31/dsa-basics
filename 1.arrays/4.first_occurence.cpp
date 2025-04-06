#include <iostream>
#include <algorithm>

using namespace std;

//although it is first occurence but it is done through optimized binary search

int optimised_binary_search(int *arr, int n, int key){
    int start = 0;
    int end = n-1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid;  // Instead of `mid - 1`, keep `mid` in case it's the answer
    }
    if(arr[start == key]){
        return start;
    }
    else return -1;
}



int main(){
    int arr[] = {1, 2, 4, 4, 4, 5, 6, 6, 6, 7, 7, 8};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin >> key;

    sort(arr, arr+n);
    int index = optimised_binary_search(arr,n,key);
    if(index != -1){
        cout << key << " is first present at index " << index << endl;
    }
    else{
        cout << key << " is not found! " <<endl;
    }
    return 0;
}
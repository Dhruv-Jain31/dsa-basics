#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int *arr, int n, int key){
    int start = 0;
    int end = n-1;

    while(start <= end){
        //int mid = (start + end)/2;
        //int mid = start + (end - start)/2; // prevents overflow i.e if start and end are large numbers then there addition
        //is larger. so it prevents it

        int mid = start + ((end - start) >> 1); // Bitwise shifts are faster than div. / 2 is the same as shifting right by 1 bit (>> 1).
        if (arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}



int main(){
    int arr[] = {12,34,31,25,32,45,78};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin >> key;

    sort(arr, arr+n);
    int index = binary_search(arr,n,key);
    if(index != -1){
        cout << key << " is present at index " << index << endl;
    }
    else{
        cout << key << " is not found! " <<endl;
    }
    return 0;
}
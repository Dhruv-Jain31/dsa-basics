#include <iostream>

using namespace std;

int largestSubarraySum1(int arr[], int n){
    int largest_sum = 0;
    int start_index = 0, end_index = 0;

    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){

            int subarraySum = 0;
            for (int k = i; k<=j; k++){
                subarraySum +=arr[k];
            }

            if(subarraySum > largest_sum){
                largest_sum = subarraySum;
                start_index = i;
                end_index = j;
            }
        }
    }

    cout << "Largest subarray sum: " << largest_sum << endl;
    cout << "subarray is: ";
    for(int i = start_index; i <= end_index; i++){
        cout << arr[i] << ",";
    }
    cout << endl;

    return largest_sum;
}

int prefix_sum(int arr[], int n){
    int prefix_sum[100] = {0};
    prefix_sum[0] = arr[0];
    int largest_sum = 0;
    int start_index = 0, end_index = 0;

    for(int i = 1; i<n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int subarray_sum = i>0 ? prefix_sum[j] - prefix_sum[i-1] : prefix_sum[j];
            if (subarray_sum > largest_sum){
                largest_sum = subarray_sum;
                start_index = i;
                end_index = j;
            }
        }
    }
    cout << "Largest subarray sum by prefix_sum: " << largest_sum << endl;
    cout << "subarray is: ";
    for(int i = start_index; i <= end_index; i++){
        cout << arr[i] << ",";
    }
    cout << endl;

    return largest_sum;
}

int main(){
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);
    cout << "largest_subarray by brute_force is: " << endl;
    largestSubarraySum1(arr,n);
    cout << "largest_subarray by prefix sum is: " << endl;
    prefix_sum(arr,n);

    return 0;
}
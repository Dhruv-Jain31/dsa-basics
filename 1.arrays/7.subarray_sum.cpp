#include <iostream>
#include <climits>

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

//works in O(N^2) times
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

//in O(N)

int kadane_algorithm(int arr[], int n){
    int current_sum = 0, largest_sum = INT_MIN;
    int start_index = 0, temp = 0, end_index = 0;

    for(int i = 0; i<n; i++){
        current_sum += arr[i];
        if(current_sum > largest_sum){
            largest_sum = current_sum;
            start_index = temp;
            end_index = i;
        }

        if(current_sum < 0){
            current_sum = 0;
            temp = i + 1;
        }
    }

    cout << "Largest subarray sum by kadane's algo is : " << largest_sum << endl;
    cout << "subarray is: ";
    for(int i = start_index; i <= end_index; i++){
        cout << arr[i] << ",";
    }
    cout << endl;
    return largest_sum;
}

int main(){
    int arr[] = {-2,3,4,-1,5,-12,6,1,3,2};
    int n = sizeof(arr)/sizeof(int);
    largestSubarraySum1(arr,n);
    prefix_sum(arr,n);
    kadane_algorithm(arr,n);

    return 0;
}
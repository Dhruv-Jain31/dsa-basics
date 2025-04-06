#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int>&a, int start, int end){
    int temp;
    while(start < end){
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}


vector<int> K_rotate_clockwise(vector<int> a, int k){
    int n = a.size();
    k = k%n;

    reverse_array(a,0,n-k-1);
    reverse_array(a,n-k,n-1);
    reverse_array(a,0,n-1);
    return a;
}

vector<int> K_rotate_anticlockwise(vector<int> a, int k){
    int n = a.size();
    k = k%n;

    reverse_array(a,0,k-1);
    reverse_array(a,k,n-1);
    reverse_array(a,0,n-1);
    return a;
}

int main() {
    vector<int> A = {1, 3, 5, 7, 9, 11};

    cout << "Enter how many times the array must be rotated (size: " << A.size() << "): ";
    int k;
    cin >> k;

    vector<int> rotated_clockwise = K_rotate_clockwise(A, k);
    vector<int> rotated_anticlockwise = K_rotate_anticlockwise(A, k);

    cout << "Rotated array anticlockwise: ";
    for (int num : rotated_anticlockwise) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Rotated array clockwise: ";
    for (int num : rotated_clockwise) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}
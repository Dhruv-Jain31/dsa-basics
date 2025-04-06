#include<iostream>
#include<vector>
using namespace std;

vector<int> counting_sort(vector<int> v){
    int largest = -1;
    int n = v.size();
    for(int i = 0; i<n; i++){
        largest = max(largest,v[i]);
    }
    //creating the count array/vector
    vector<int> freq(largest + 1, 0);
    for(int i = 0; i<n; i++){
        freq[v[i]]++;
    }

    //put back elements from frequency into original array
    int j = 0;
    for(int i = 0; i<=largest; i++){
        while(freq[i] > 0){
            v[j] = i;
            freq[i] --;
            j++;
        }
    }
    return v;
}

int main(){
    vector<int> v ={5,8,3,1,1,2,6};
    v = counting_sort(v);

    for(auto x : v){
        cout << x << ",";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int>v){
    int n = v.size();
    for(int i = 1; i <= n-1; i++){
        int current = v[i];
        int prev = i - 1;
        while(prev >= 0 && v[prev] > current){
            v[prev+1] = v[prev];
            prev--;
        }
        v[prev + 1] = current;
        cout<< "vector after " << i << " pass is: ";
        for(auto x : v){
            cout << x << ",";
        }
        cout << endl;
    }
}


int main(){
    vector<int> v ={4,3,5,1,2};
    insertion_sort(v);

    /*for(auto x : v){
        cout << x << ",";
    }*/
}
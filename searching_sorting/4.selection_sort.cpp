#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>v){
    int n = v.size();
    for(int pos = 0; pos <= n-2; pos++){
        int current = v[pos];
        int min_position = pos;
        for(int j = pos; j<n; j++){
            if(v[j] < v[min_position]){
                min_position = j;
            }
        }
        swap(v[min_position],v[pos]);
        cout<< "vector after " << pos + 1 << " pass is: ";
        for(auto x : v){
            cout << x << ",";
        }
        cout << endl;
    }
}

int main(){
    vector<int> v ={5,4,1,3,2};
    selection_sort(v);

    /*for(auto x : v){
        cout << x << ",";
    }*/
}
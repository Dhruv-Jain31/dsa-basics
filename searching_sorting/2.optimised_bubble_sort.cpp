#include<iostream>
#include<vector>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> v){
    // your code  goes here
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j+1]){
                flag = true;
                swap(v[j],v[j+1]);
            }
        }
        cout<< "vector after " << i+1 << " pass is: ";
        for(auto x : v){
            cout << x << ","; 
        }
        cout << endl;
        if(flag == false){
            break;
        }
    }
    return v;
}


int main(){
    vector<int> v ={4,3,5,1,2};
    optimizedBubbleSort(v);

    /*for(auto x : v){
        cout << x << ",";
    }*/
}

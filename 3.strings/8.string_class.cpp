#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s = "hello world"; //dynamic array

    string d("hello world 2"); //calling the constructor to make the object

    cout << s << endl << d << endl;

    string e;
    getline(cin,e,'.'); // will get the input string store it to string e and gets terminated with '.'

    for (char ch : e){
        cout << ch << ",";
    }

    cout << endl;

    //to get multiple strings
    int n = 5;
    vector<string> sarr;
    cin.get();

    string temp;
    while(n--){
        getline(cin,temp);
        sarr.push_back(temp);
    }

    for(string x: sarr){
        cout << x << "," << endl;
    }

    return 0;
}


#include<iostream>
using namespace std;

int main(){
    int x = 10;
    float y = 5.5;

    cout << &x << endl; // & is the address of operator and prints address of x

    int * xptr = &x; // pointer xptr stores value of address of x

    cout << xptr << endl;

    //address of pointer variable
    cout << &xptr << endl; // printing address of xptr

    //pointer to a pointer
    int ** xxptr = &xptr; // stores address of xptr

    cout << xxptr << endl;

    cout << &xxptr << endl;

    int *** xxxptr = &xxptr;

    cout << xxxptr << endl;

    return 0;
}
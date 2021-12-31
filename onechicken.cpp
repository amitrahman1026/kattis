#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a > b){
        if(a-b == 1){
                cout << "Dr. Chaz needs 1 more piece of chicken!\n";
            }
        else{
            cout << "Dr. Chaz needs " << a - b << " more pieces of chicken!\n";
        }
        return 0;
    }
    if (a < b){
        if(b-a == 1){
            cout << "Dr. Chaz will have 1 piece of chicken left over!\n";
        }
        else{
            cout << "Dr. Chaz will have " << b - a << " pieces of chicken left over!\n";
            }
        return 0;
    }
}
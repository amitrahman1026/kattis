#include <iostream>
using namespace std;

int main(){
    int left, right;
    cin >> left >> right;
    if(left == 0 && right == 0){
        cout << "Not a moose";
        return 0;
    }

    if(left == right){
        cout << "Even ";
    }
    else{
        cout << "Odd ";
    }
    cout << 2 * max(left, right);
}
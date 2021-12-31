#include <iostream>
using namespace std;

int main(){
    double X, Y;
    cin >> X >> Y;
    
    if(Y == 1){
        if(X == 0){
            cout << "ALL GOOD";
        }
        else{
            cout << "IMPOSSIBLE";
        }
    }
    else{
        cout << fixed;
        cout.precision(9);
        cout << X/(1-Y);
    }
}
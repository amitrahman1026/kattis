#include <iostream>
using namespace std;

int main(){
    int g, s, c, buyingPower;

    cin >> g >> s >> c;
    
    buyingPower = g * 3 + s * 2 + c;
    
    if(buyingPower >= 8){
        cout << "Province or ";
    }
    else if(buyingPower >= 5){
        cout << "Duchy or ";
    }
    else if(buyingPower >= 2){
        cout << "Estate or ";
    }

    if(buyingPower >= 6){
        cout << "Gold" << endl;
    }
    else if(buyingPower >= 3){
        cout << "Silver" << endl;
    }
    else{
        cout << "Copper" << endl;
    }
    return 0;
}
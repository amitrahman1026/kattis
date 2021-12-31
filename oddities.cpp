#include <iostream>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    int num;
    for(int i = 0; i < testCases; i++){
        cin >> num;
        if(num % 2 == 0){
            cout << num << " is even\n";
        }
        else{
            cout << num << " is odd\n";
        }
    }
    return 0;
}
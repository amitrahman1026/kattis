#include <iostream>
using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    for(int i = 1; i <= n; i++){
        if(i % x == 0 && i % y == 0){
            cout << "FizzBuzz\n";
            continue;
        }
        
        if(i % x == 0){
            cout << "Fizz\n";
            continue;
        }
        if(i % y == 0){
            cout << "Buzz\n";
            continue;
        }
        cout << i << endl; 
    }
}

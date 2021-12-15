#include <iostream>
using namespace std;

int main(){
    int a,b,c,n;
    
    cin >> a >> b >> c >> n;

    if(a == 0 || b == 0 || c == 0 || n < 3 || (a + b +c) < n){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}
#include <iostream>
using namespace std;

int main(){
    int n;
    double a, b;
    double ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        cin >> b;
        ans += a * b;
    }
    cout << ans;
}
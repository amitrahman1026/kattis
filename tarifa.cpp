#include <iostream>
using namespace std;

int main(){
    int X, N, temp;
    cin >> X;
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> temp;
        ans += (X-temp);
    }
    cout << ans+X;
}
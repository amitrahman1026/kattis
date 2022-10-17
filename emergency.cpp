#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        
    ll n, k;
    cin >> n >> k;
    if (k < n)
    {
        cout << k + ((2*k <= (n-1))?1:0) + ((n-1)%k);
        return 0;
    }
    else
    {
        cout << n - 1;
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    sort(v.begin(),v.end());


    long long ans=0,w;

    for (int i= 1;i<n;i++){
        w = v[0]+v[i];
        ans += w;
    } 
    cout << ans;
}
// THIS IS THE END OF THE FILE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, Q, temp;

    cin >> N >> Q;

    multiset<ll> s;
    for (ll i = 0; i < N; i++)
    {
        cin >> temp;
        s.insert(temp);
    }

    ll T, D;
    for (ll i = 0; i < Q; i++)
    {
        cin >> T >> D;

        if (T == 1)
        { // discard strictly harder than D
            auto it = s.upper_bound(D);

            if (it == s.end())
            {
                cout << "-1\n";
            }
            else
            {
                cout << *it << "\n";
                s.erase(it);
            }
        }
        if (T == 2)
        { // discard lower or equal to D
            auto it = s.lower_bound(D);
            if (s.empty() ||
                (it == s.begin() && *it > D)) // either empty or the first elemnet is greater than D, you dont discard
            {
                cout << "-1\n";
                // continue;
            }
            else if (*it == D) // not empty, any element == D
            {
                cout << *it << "\n";
                s.erase(it);
            }
            else if (it != s.begin()) // any element < D within the list
            {
                it--;
                cout << *it << "\n";
                s.erase(it);
            }
            else 
            {
                cout << *it << "\n";
                s.erase(it);
            }
        }
    }
}


// THIS IS THE END OF THE FILE
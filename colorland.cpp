#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <unordered_map>

#define INF 1e9

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    unordered_map<string, int> m;
    for (int i = n - 1; i >= 0; i--)
    {
        m.insert({v[i], INF});
    } // hashmap to track min steps of colours

    m[v[n - 1]] = 0; // init end as 0 steps

    for (int i = n - 2; i >= 0; i--)
    { // next block from end towards source
        string currColour = v[i];
        int currMin = INF;
        for (auto &[colour, minStep] : m)
        {
            currMin = min(currMin, minStep);
        }
        m[currColour] = currMin + 1;
    }

    int currMin = INF;
    for (auto &[colour, minStep] : m)
    {
        currMin = min(currMin, minStep);
    }
    cout << currMin + 1;

    return 0;
}

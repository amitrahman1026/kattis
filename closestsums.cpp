#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, casenum = 1, m, q;
    while (cin >> n)
    {
        cout << "Case " << casenum << ":\n";
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int sum, closest;
        // queries
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> q;
            closest = v[0]+v[1];
            for (int j = 0; j < n; j++)
            {
                for (int k = 1; k < n; k++)
                {
                    if(k!=j){
                    sum = v[k] + v[j];
                    }
                    if (abs(sum - q) < abs(closest - q))
                    {
                        closest = sum;
                    }
                }
            }
            cout << "Closest sum to " << q << " is " << closest << ".\n";
        }
        casenum++;
    }
}
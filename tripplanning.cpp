/**
 * @file tripplanning.cpp
 * @author amit rahman A0244348B
 * @date 2022-03-23
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M, a, b, num = 1;

    cin >> N >> M;

    vector<long> v(N, -1);

    while (M--)
    {
        cin >> a >> b;
        if (abs(a - b) == 1)
        {
            v[min(a, b) - 1] = num;
        }
        if (abs(a - b) == N - 1)
        {
            v[N - 1] = num;
        }
        num++;
    }
    if (find(v.begin(), v.end(), -1) != v.end())
    {
        cout << "impossible";
    }
    else
    {
        for (long i = 0; i < N; i++)
        {
            cout << v[i] << '\n';
        }
    }
}
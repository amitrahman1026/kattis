#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N;
    string input;
    cin >> N;
    vector<string> v;
    for (long i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    long a, b;
    for (long i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        v[a] = v[a] + v[b];
        v[b] = "";
    }
    for (auto& i : v)
    {
        cout << i;
    }
}
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w;
    cin >> w;
    for (int i = 1; i < w; i++)
    {
        if (i % 2 == 0 && (w - i) % 2 == 0)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}

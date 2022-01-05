#include <iostream>
using namespace std;

int main()
{
    int n, m, temp;
    cin >> n >> m;
    int sum = 0;
    int count = 0;
    while (cin >> temp)
    {
        if ((sum += temp) > n)
        {
            break;
        }
        count++;
        // cout << sum << endl;
    }
    cout << m - count;
}
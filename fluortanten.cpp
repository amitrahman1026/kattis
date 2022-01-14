#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, temp, highestHappiness = 0;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n - 1; i++)
    {
        cin >> temp;
        if (temp != 0)
        {
            a[i] = temp;
        }
        else
        {
            cin >> a[i];
        }
        // cout << a[i];
        highestHappiness += (i + 1) * a[i];
    }
    // cout << '\n';
    temp = highestHappiness;
    for (long long i = n - 1; i >= 1; i--)
    {
        temp += a[i - 1];
        if (temp >= highestHappiness)
        {
            highestHappiness = temp;
        }
    }
    cout << highestHappiness << "\n";
}

#include <iostream>
using namespace std;

int main()
{
    int n, min, min_index, temp;
    cin >> n;
    cin >> min;
    min_index = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        if (temp < min)
        {
            min = temp;
            min_index = i;
        }
    }
    cout << min_index;
}
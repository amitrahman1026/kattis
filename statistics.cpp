#include <iostream>
using namespace std;

int main()
{
    int temp, n;
    int i = 1;
    while (cin >> temp)
    {
        int min, max, range;
        n = temp;
        cin >> max;
        min = max;
        for (int j = 1; j < n; j++)
        {
            cin >> temp;
            if (temp < min)
            {
                min = temp;
            }
            if (temp > max)
            {
                max = temp;
            }
        }
        range = max - min;
        cout << "Case " << i << ": " << min << " "
             << max << " " << range << endl;
        i++;
    }
}

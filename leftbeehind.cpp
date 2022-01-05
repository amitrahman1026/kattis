#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
        {
            break;
        }
        if (a + b == 13)
        {
            cout << "Never speak again." << endl;
            continue;
        }

        else if (a > b)
        {
            cout << "To the convention." << endl;
            continue;
        }
        else if (a < b)
        {
            cout << "Left beehind." << endl;
        }
        else
        {
            cout << "Undecided." << endl;
            continue;
        }
    }
}

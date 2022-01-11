#include <iostream>
using namespace std;

int main()
{
    int n;
    string input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (i % 2 == 0)
        {
            cout << input << endl;
        }
    }
}
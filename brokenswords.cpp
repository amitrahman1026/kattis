#include <iostream>
using namespace std;

int main()
{
    int n, tb = 0, lr = 0;
    cin >> n;
    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input[0] == '0')
        {
            tb++;
        }
        if (input[1] == '0')
        {
            tb++;
        }
        if (input[2] == '0')
        {
            lr++;
        }
        if (input[3] == '0')
        {
            lr++;
        }
    }
    int swords, slatsUsed;
    swords = min(tb/2, lr/2);
    slatsUsed = swords * 2;
    cout << swords << " " << tb - slatsUsed << " " << lr - slatsUsed;
}

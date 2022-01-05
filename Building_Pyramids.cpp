#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int height = 0;
    int blocks;
    cin >> blocks;
    if (blocks == 0)
    {
        cout << 0;
        return 0;
    }
    int i = 1;
    int count = 0;
    while (count <= blocks)
    {
        count += pow(i, 2);
        if (count > blocks)
        {
            break;
        }
        height++;
        i += 2;
    }
    cout << height;
}

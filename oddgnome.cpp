#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int king;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        
        int king_index = 0;
        cin >> king;

        int temp;
        
        for (int j = 1; j < m; j++)
        {
            cin >> temp;
            if (temp - king == 1)
            {
                king = temp;
            }
            else
            {
                king = temp;
                king_index = j + 1;
                cout << king_index << endl;
                break;
            }
        }
    }
}
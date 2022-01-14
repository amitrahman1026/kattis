#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, king_index = 0;
        cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++){
            cin >> a[i];
        }
        for (int i = 0; i < m-1; i++)
        {
            if (a[i+1] - a[i] != 1)
            {
                king_index = i + 2;
                cout << king_index << endl;
                break;
            }
        }
    }
}
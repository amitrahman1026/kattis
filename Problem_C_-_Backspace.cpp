#include <iostream>
#include <vector>

using namespace std;

int main()
{
    char c;
    vector<char> v;

    while (cin >> c)
    {
        if (c == '<' && !v.empty())
        {
            v.pop_back();
        }
        else
        {
            v.push_back(c);
        }
    }
    for (long i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}

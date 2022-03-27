#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    long n;
    string name, cmd, a, b;
    cin >> n;
    vector<string> v(n);

    for (long i = 0; i < n; i++)
    {
        cin >> name;
        v.push_back(name);
    }

    cin >> n;
    
    for (long i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "cut")
        {
            cin >> a >> b;
            auto pos =  find(v.begin(), v.end(), b);
            v.insert(pos, a);
        }

        if (cmd == "leave")
        {
            cin >> a;
            auto pos =  find(v.begin(), v.end(), a);
            v.erase(pos);
        }
    } 
    for (long i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}
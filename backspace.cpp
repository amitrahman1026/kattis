#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input, output;
    cin >> input;

    for (auto i : input)
    {
        if (i == '<')
        {
            output.pop_back();
        }
        else
        {
            output.push_back(i);
        }
    }
    cout << output;
}

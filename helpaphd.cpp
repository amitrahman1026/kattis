#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string input;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> input;
        if (input == "P=NP")
        {
            cout << "skipped\n";
            continue;
        }
        int operatorPosition;
        for (int j = 0; j < input.length(); j++)
        {
            if (input[j] == '+')
            {
                operatorPosition = j;
                break;
            }
        }
        a = stoi(input.substr(0, operatorPosition));
        b = stoi(input.substr(operatorPosition, input.length()));
        cout << a + b << endl;
        // expression = input - '0';
    }
}

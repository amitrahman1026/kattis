#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[2048];
    cin >> input;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ':' || input[i] == ';')
        {
            if (i < strlen(input) - 1 && input[i + 1] == ')')
            {
                cout << i << endl;
            }
            if (i < strlen(input) - 2 && input[i + 1] == '-' && input[i+2] == ')'){
                cout << i << endl;
            }
 
        }
    }
}

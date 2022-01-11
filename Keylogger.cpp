#include <iostream>
#include <string>
using namespace std;

char parser(string input)
{
    char parsed;
    if (input == "clank")
    {
        parsed = 'a';
    }
    else if (input == "bong")
    {
        parsed = 'b';
    }
    else if (input == "click")
    {
        parsed = 'c';
    }
    else if (input == "tap")
    {
        parsed = 'd';
    }
    else if (input == "poing")
    {
        parsed = 'e';
    }
    else if (input == "clonk")
    {
        parsed = 'f';
    }
    else if (input == "clack")
    {
        parsed = 'g';
    }
    else if (input == "ping")
    {
        parsed = 'h';
    }
    else if (input == "tip")
    {
        parsed = 'i';
    }
    else if (input == "cloing")
    {
        parsed = 'j';
    }
    else if (input == "tic")
    {
        parsed = 'k';
    }
    else if (input == "cling")
    {
        parsed = 'l';
    }
    else if (input == "bing")
    {
        parsed = 'm';
    }
    else if (input == "pong")
    {
        parsed = 'n';
    }
    else if (input == "clang")
    {
        parsed = 'o';
    }
    else if (input == "pang")
    {
        parsed = 'p';
    }
    else if (input == "clong")
    {
        parsed = 'q';
    }
    else if (input == "tac")
    {
        parsed = 'r';
    }
    else if (input == "boing")
    {
        parsed = 's';
    }
    else if (input == "boink")
    {
        parsed = 't';
    }
    else if (input == "cloink")
    {
        parsed = 'u';
    }
    else if (input == "rattle")
    {
        parsed = 'v';
    }
    else if (input == "clock")
    {
        parsed = 'w';
    }
    else if (input == "toc")
    {
        parsed = 'x';
    }
    else if (input == "clink")
    {
        parsed = 'y';
    }
    else if (input == "tuc")
    {
        parsed = 'z';
    }
    return parsed;
}

void toggle(bool &capital)
{
    if (capital == true)
    {
        capital = false;
    }
    else
    {
        capital = true;
    }
}

int main()
{
    int n;
    cin >> n;
    string input;
    bool capital = false;
    string output = "";
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input == "whack")
        {
            output.push_back(' ');
            continue;
        }

        if (input == "pop") // backspace
        {
            if (output.length() == 0)
            {
                continue;
            }
            output.pop_back();
            continue;
        }

        if (input == "dink" || input == "thumb" || input == "bump") // toggle using shift or caps
        {
            toggle(capital);
            continue;
        }
        // if (input == "bump") // pressing caps
        // {
        //     toggle(capital);
        //     continue;
        // }

        char parsed = parser(input);

        if (capital == true)
        {
            parsed -= (int)('a' - 'A');
        }
        output.push_back(parsed);
    }
    cout << output;
}
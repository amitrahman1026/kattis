#include <iostream>
#include <string>
using namespace std;

char parser(string input)
{
    if (input == "clank")
    {
        return 'a';
    }
    else if (input == "bong")
    {
        return 'b';
    }
    else if (input == "click")
    {
        return 'c';
    }
    else if (input == "tap")
    {
        return 'd';
    }
    else if (input == "poing")
    {
        return 'e';
    }
    else if (input == "clonk")
    {
        return 'f';
    }
    else if (input == "clack")
    {
        return 'g';
    }
    else if (input == "ping")
    {
        return 'h';
    }
    else if (input == "tip")
    {
        return 'i';
    }
    else if (input == "cloing")
    {
        return 'j';
    }
    else if (input == "tic")
    {
        return 'k';
    }
    else if (input == "cling")
    {
        return 'l';
    }
    else if (input == "bing")
    {
        return 'm';
    }
    else if (input == "pong")
    {
        return 'n';
    }
    else if (input == "clang")
    {
        return 'o';
    }
    else if (input == "pang")
    {
        return 'p';
    }
    else if (input == "clong")
    {
        return 'q';
    }
    else if (input == "tac")
    {
        return 'r';
    }
    else if (input == "boing")
    {
        return 's';
    }
    else if (input == "boink")
    {
        return 't';
    }
    else if (input == "cloink")
    {
        return 'u';
    }
    else if (input == "rattle")
    {
        return 'v';
    }
    else if (input == "clock")
    {
        return 'w';
    }
    else if (input == "toc")
    {
        return 'x';
    }
    else if (input == "clink")
    {
        return 'y';
    }
    else if (input == "tuc")
    {
        return 'z';
    }
    else if(input == "whack") {
        return ' ';
    }
}

int main()
{
    int n;
    cin >> n;
    string input;
    
    string output = "";
    for (int i = 0; i < n; i++)
    { 
        cin >> input;
        if (input == "dink") // holding down shift
        {
            string temp;
            cin >> temp;
            // cout << temp;
            while (temp != "thumb" && i < n)
            {
                output.push_back(toupper(parser(temp)));
                i++;
            }
        }
        if (input == "bump") // pressing caps
        {
            string temp;
            cin >> temp;
            // cout << temp;
            while (temp != "bumb" && i < n)
            {
                output.push_back(toupper(parser(temp)));
                i++;
            }
        }
        if (input == "pop") // backspace
        {
            output.pop_back();
            i++;
        }
        output.push_back(parser(input));
    }
    cout << output;
}
/**
 * @file Problem_A_Sim.cpp
 * @author Amit Rahman, A0244348B
 *
 */

#include <iostream>
#include <string>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    string input, output;
    list<char> ls;
    // Deque dq;
    // bool front = true;
    long t;
    cin >> t;
    cin.ignore();

    for (long j = 0; j < t; j++)
    {
        getline(cin, input);
        // cin >> input;
        // cout << t << input;

        list<char>::iterator it = ls.begin();

        for (long i = 0; i < input.length(); i++)
        {
            if (input[i] == '<')
            {
                list<char>::iterator prev = it;
                prev--;
                list<char>::iterator front = ls.begin();
                front--;

                if (prev == front)
                {
                    continue;
                }
                ls.erase(prev);
            }
            else if (input[i] == '[')
            {
                it = ls.begin();
            }
            else if (input[i] == ']')
            {
                it = ls.end();
            }
            else
            {
                ls.insert(it, input[i]);
            }
        }
        for (auto i : ls)
        {
            cout << i;
        }
        cout << '\n';
        ls.clear();
    }
    return 0;
}
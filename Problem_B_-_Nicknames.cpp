/**
 * @file Problem_B_-_Nicknames.cpp
 * @author Amit Rahman, A02448348B
 * 
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A, B;
    string name, temp;
    long count = 1;

    map<string, long> db;

    cin >> A;
    for (long i = 0; i < A; i++)
    {
        cin >> name;
        for (long j = 0; j < name.length(); j++)
        {
            temp = name.substr(0, j + 1);
            if (!db.count(temp))
            {
                db.insert({temp, count});
            }
            else
            {
                db[temp]++;
            }
        }
    }

    cin >> B;
    for (long i = 0; i < B; i++)
    {
        cin >> name;
        cout << db[name] << "\n";
    }
    return 0;
}
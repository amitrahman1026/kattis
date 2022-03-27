/**
 * @file quickscope.cpp
 * @author Amit Rahman A0244348B
 * @date 2022-03-20
 *
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N;
    string varName, varType, input;
    cin >> N;
 
    stack<unordered_set<string>> blockDecls;

    unordered_set<string> outerblock;
    blockDecls.push(outerblock);

    unordered_map<string, vector<string>> varDecls;

    while (N--)
    {
        cin >> input;

        if (input == "{")
        {
            unordered_set<string> temp_set;
            blockDecls.push(temp_set);
        }

        if (input == "DECLARE")
        {
            cin >> varName >> varType;
            // variables been declared before in this block
            if (blockDecls.top().count(varName) == 1)
            {
                cout << "MULTIPLE DECLARATION\n";
                return 0;
            }
            // variable does not exist
            if (varDecls.count(varName) == 0)
            {
                vector<string> v;
                varDecls.insert({varName, v});
            }
            varDecls[varName].push_back(varType);

            blockDecls.top().insert(varName);
        }

        if (input == "TYPEOF")
        {
            cin >> varName;

            if (varDecls.count(varName) != 0)
            {
                long n = varDecls[varName].size() - 1;

                cout << varDecls[varName][n] << "\n";
            }
            else
            {
                cout << "UNDECLARED\n";
            }
        }

        if (input == "}")
        {
            while (!blockDecls.top().empty())
            {
                auto temp = blockDecls.top().begin();
                varDecls[*temp].pop_back();
                if (varDecls[*temp].empty())
                {
                    varDecls.erase(*temp);
                }
                blockDecls.top().erase(temp);
            }
            blockDecls.pop();
        }
    }
}

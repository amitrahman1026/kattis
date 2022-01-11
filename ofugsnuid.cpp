#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        stack.push(temp);
    }
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}
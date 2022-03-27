/**
 * @file Problem_B_Bungee_Builder.cpp
 * @author Amit Rahman, A0244348B
 *
 */

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long n, temp, ans = 0;
    cin >> n;
    vector<long> v;
    for (long i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    stack<pair<long, long>> st;

    for (long j = 0; j < n; j++)
    {
        long base = -1;
        // long l = v[0];
        // int topBase = st.top().second or st.top().first, depending on the value of st.top().second

        while (!st.empty() && v[st.top().first] < v[j])
        {
            long topBase;
            
            if(st.top().second == -1){
                topBase = st.top().first;}
            else if(st.top().second != -1){
                topBase = st.top().second;
            }
            if(base == -1 || v[base] > v[topBase]){
                base = topBase;
            }

            // cout<<"Popping: {"<< st.top().first <<","<< st.top().second <<"}\n";
            st.pop();
            // cout << v[j] - v[base] << '\n';
            // ans = max(v[j]- v[base], ans);
            ans = max(min(v[j], v[st.top().first])- v[base], ans);
        } // all smaller mountains have been removed from stack && min base thus far has been stored
        // cout<<"Pushing: {"<< j <<","<< base <<"}\n";
        st.push(make_pair(j, base));
    }

    // while (!st.empty())
    // {
    //     cout << '\n'
    //          << st.top().first << ',' << st.top().second << " \n";
    //     st.pop();
    // }
    // for (auto i:v) cout << i << " ";
    cout << ans;
    return 0;
}
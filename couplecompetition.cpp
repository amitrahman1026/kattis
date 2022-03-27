/**
 * @file couplecompetition.cpp
 * @author Amit Rahman A0244348B
 * @date 2022-03-27
 * 
 * 
 */

#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct comp
{
    bool operator()(const pair<long,long> &lhs, const pair<long,long> &rhs) const
    {
        return lhs.first > rhs.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, h;
    cin >> N;
    vector<long> v(N), left(N), right(N);
    vector<pair<long,long>> v_pair;
    vector<long> d(N, 10000000);
    stack<long> st;
    // multimap<long, long, comp> m;


    for (long i = 0; i < N; i++)
    {
        cin >> h;
        v[i] = h;
        // init left and right;
        left[i] = i;
        right[i] = i;
        // m.insert({h, i});
        v_pair.push_back({h,i});
    }

    sort(v_pair.begin(),v_pair.end(),comp{});
    // left parents
    for (long i = 0; i < N; i++)
    {
        while (!st.empty() && v[st.top()] <= v[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            left[i] = st.top();
        }
        st.push(i);
    }

    // reverse(v.begin(), v.end());

    while (!st.empty())
    {
        st.pop();
    }

    // for (long i = 0; i < N; i++)
    // {
    //     cout << right[i] << " ";
    // }
    // cout << '\n';

    // right parents
    for (long i = N - 1; i > -1; i--)
    {
        while (!st.empty() && v[st.top()] <= v[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            right[i] = st.top();
        }
        st.push(i);
    }

    // reverse(right.begin(), right.end());

    // for (long i = 0; i < N; i++)
    // {
    //     cout << left[i] << " ";
    // }
    // cout << '\n';
    // for (long i = 0; i < N; i++)
    // {
    //     cout << right[i] << " ";
    // }
    // cout << '\n';

    // cout << m.size();
    
    for (long i = 0; i < N; i++)
    {
        long curr = v_pair[i].second;
        
        
        d[curr] = min(d[left[curr]], d[right[curr]]) + 1;
        if (d[curr] > 10000000)
        {
            d[curr] = 0;
        } 
        // m.erase(m.begin());
    }

    for (long i = 0; i < N; i++)
    {
        cout << d[i] << " ";
    }

    return 0;
}
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
    long n, temp, ans = 0, tallest = 0, tallest_index = 0;
    cin >> n;
    vector<long> v;
    for (long i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp>tallest){
            tallest_index = i;
            tallest = temp;
        }
        v.push_back(temp);
    }

    stack<pair<long, long>> st;

    
    for (long i = tallest_index-1; i < -1; i--)
    {
        long current_max_jump = 0;
        
        while (!st.empty() && v[st.top().first] < v[i])
        { 
            // long pop_height = v[st.top().first];
            
            current_max_jump = max(v[i] - v[st.top().first] + st.top().second, current_max_jump);
            st.pop();

        } // all smaller mountains have been removed from stack && max possible jump for each taller
        // peak thus far has been stored

        st.push(make_pair(i, current_max_jump));
        ans = max(current_max_jump, ans);
        // cout << st.top().second << "/";
    }

    while (!st.empty())
    {
        st.pop();
    }


    for (long j = tallest_index+1; j < n; j++)
    {
        long current_max_jump = 0;
        
        while (!st.empty() && v[st.top().first] < v[j])
        { 
            // long pop_height = v[st.top().first];
            
            current_max_jump = max(v[j] - v[st.top().first] + st.top().second, current_max_jump);
            st.pop();

        } // all smaller mountains have been removed from stack && max possible jump for each taller
        // peak thus far has been stored

        st.push(make_pair(j, current_max_jump));
        ans = max(current_max_jump, ans);
        // cout << st.top().second << "/";
    }




    cout << ans << '\n';
    // for (auto i:v) cout << i << " ";gg=G
    return 0;    
}

/**
 * @file Problem_B_Bungee_Builder.cpp
 * @author Amit Rahman, A0244348B
 *
 */
/*
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
        long current_max_jump = 0;
        
        while (!st.empty() && v[st.top().first] < v[j])
        { 
            // long pop_height = v[st.top().first];
            
            current_max_jump = max(v[j] - v[st.top().first] + st.top().second, current_max_jump);
            st.pop();

        } // all smaller mountains have been removed from stack && max possible jump for each taller
        // peak thus far has been stored

        st.push(make_pair(j, current_max_jump));
        ans = max(current_max_jump, ans);
        // cout << st.top().second << "/";
    }

    // while (!st.empty())
    // {
    //     cout << '\n'
    //          << st.top().first << ',' << st.top().second << " \n";
    //     st.pop();
    // }
    cout << ans << '\n';
    // for (auto i:v) cout << i << " ";
    return 0;    
}*/
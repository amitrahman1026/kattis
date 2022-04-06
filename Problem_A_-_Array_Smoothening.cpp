// PL2_4M4R

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, K, input;
    cin >> N >> K;

    unordered_map<long, long> m;

    for (long i = 0; i < N; i++) // read in O(N)
    {
        cin >> input;
        if((!m.count(input))){
            m.insert({input,1});
            continue;
        }
        m[input]++;
    }

    multimap<long, long,greater<long>> m_count;
    long key,T;
    for(auto &it:m){ //O(aN) where a in number of unique elements
        key = it.first;
        T = it.second; //O(N)
        // cout <<"inserting " <<key<<" "<<T << '\n';
        m_count.insert({T,key}); // O(logN)
    }
    // m[1]--;
    // cout << m[1];
    
    long top_key,new_cnt;

    while(K){ // O(NlogN) as K is up to N
        top_key = m_count.begin()->second;
        m[top_key]--; // O(1)
        // cout << m[top_key] << '\n';
        new_cnt = m[top_key]; 
        m_count.erase(m_count.begin()); //O(logN)
        m_count.insert({new_cnt,top_key}); //O(logN)

        K--;
    }

    // cout<<"m_count\n";
    // for(auto &it:m_count){
    //     cout << it.first << " " <<it.second << '\n';
    // }
    // cout<<"m\n";
    // for(auto &it:m){
    //     cout << it.first << " " <<it.second<<'\n';
    // }

    cout << '\n' <<m_count.begin()->first;
}

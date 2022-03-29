#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct comp
{
    bool operator() (const pair<long, string>& lhs,  const pair<long, string>& rhs) const{
        if (lhs.first == rhs.first){
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, K;
    cin >> N >> K;
    long Q;

    // observation- waiting time in not relevant as waiting time only affects priorty linearly
    //  can just take {Priorty,Name} into PQ where priority is S-K*entry_time

    // priority queue
    set<pair<long,string>,comp>pq2;
    // hashmap
    map<string, long> m;

    // Queries init
    long T;
    string M;
    long S;

    while (N--)
    {
        cin >> Q;
        switch (Q)
        {
        case 1:
            cin >> T >> M >> S;
            // enter longo pq;
            pq2.insert({(S - K * T), M});
            // enter longo hasmap;
            m.insert({M, (S - K * T)});
            break;
        case 2:
            cin >> T;
            if (pq2.empty())
            {
                cout << "doctor takes a break\n";
                break;
            }
            m.erase(pq2.begin()->second);
            cout << pq2.begin()->second << '\n';
            pq2.erase(pq2.begin());
            break;
        case 3:
            cin >> T >> M;
            if (m.count(M))
            {
                pq2.erase({m[M],M});
                m.erase(M);
            }
            break;
        }
    }
}
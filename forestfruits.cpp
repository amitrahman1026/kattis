/**
 * @file forestfruits.cpp
 * @author Amit Rahman A0244348B
 * @date 2022-03-27
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> ll;
typedef vector<ll> vll;

const long long INF = 1e17;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long V, E, C, K, M;
    long u, v, w, c;
    // vector<vector<long>> v (V);

    cin >> V >> E >> C >> K >> M;

    // case where its impossible
    if (C < min(K, M))
    {
        cout << -1;
        return 0;
    }

    // find distance to each clearing, sort, take kth elem*2;

    // init AL, 0 indexed
    vector<vll> AL(V, vll());
    for (long long i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        AL[u - 1].push_back({v - 1, w});
        AL[v-1].push_back({u-1,w});
    }

    // read in clearings, 0 indexed
    vector<long long> clearings;
    vector<long long> c_dist(C);
    for (long long i = 0; i < C; i++)
    {
        cin >> c;
        clearings.push_back(c - 1);
    }

    // distance to all vertex
    vector<long long> dist(V, INF);
    dist[0] = 0;

    // dijkstras for all vertexes store in dist[i] for vertex 0
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop(); // shortest unvisited u

        if (d > dist[u])
        {
            continue;
        }

        for (auto &[v, w] : AL[u])
        { // all edges from u
            if (dist[u] + w >= dist[v])
            {
                continue;
            }
        

        dist[v] = dist[u] + w; // relax operation

        pq.push({dist[v], v});
        }
    }
    

    for (long long i = 0; i < C; i++)
    {
        c_dist[i] = dist[clearings[i]];
    }
    // sort to find shortest
    sort(c_dist.begin(),c_dist.end());
    
    // // debug
    // for (long i = 0; i < C; i++)
    // {
    //     cout << c_dist[i];
    // }
    
    // output
    
    long long output = c_dist[min(M,K) - 1] * 2;

    if (output >= INF){
        cout << -1;
        return 0;
    }
    
    cout << c_dist[min(M,K) - 1] * 2;

}
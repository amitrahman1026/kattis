#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief the idea is to look for alternaitve paths from the shortest path, if they dont exist, impossible
 * run dijkstras once, check if curre
 *
 */

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

struct edge
{
    int u;
    int v;
    int dist;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("in.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vii> AL(n, vii());
    vector<edge>EL;
    while (m--)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w); // undirected graph
        // edge e(u,v,w);
        EL.push_back({u,v,w});  // add to edge list
    }

    int s = 0; // delft, amsterdam = 1
    vi dist(n, INF);
    dist[s] = 0; // INF = 1e9 here, Delft,

    // (Modified) Dijkstra's algorithm
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())
    { // main loop
        auto [d, u] = pq.top();
        pq.pop(); // shortest unvisited u
        if (d > dist[u])
            continue; // a very important check
        for (auto &[v, w] : AL[u])
        { // all edges from u
            if (dist[u] + w >= dist[v])
                continue;          // not improving, skip
            dist[v] = dist[u] + w; // relax operation
            pq.push({dist[v], v}); // enqueue better pair
        }
    }

    // iterate thru edge list and remove edges part of the shortest path
    // to find edges in the shortest path, find dist[u] - dist[v]
    // reconstruct another adjacency list without paths in the shortest path


    vector<vi> AL2(n, vi());
    for(auto i: EL){
        if(dist[i.u] == dist[i.v] + i.dist) continue; // shortest path
        AL2[i.v].push_back(i.u); // undirected graph 
    }
    for(auto i: EL){
        if(dist[i.v] == dist[i.u] + i.dist) continue; // shortest path
        AL2[i.u].push_back(i.v);
    }
    // run bfs to check if every node has at least one remaing edge
    queue<int> q;
    q.push(0);
    vector<bool> tracking(n,false);
    vector<int>prevNode(n,-1); //initialise all nodes as having invalid parent node

    while(!q.empty()){
        auto prev = q.front();
        for(int i = 0; i < AL2[prev].size(); i++){
            int curr = AL2[prev];
            if(!tracking[i]){
                q.push(i);
                prevNode[i] = prev;
                tracking[i] = true;
            }
        }
        q.pop();
    }

    for(auto &i:prevNode){
        cout << i << " ";
    }

    if(prevNode[1] == -1){
        cout << "impossible\n";
        return 0;
    }
    
    // vector<int> pathTaken;
    // int curr = 1; // work backwards from 1 to 0
    // while(prevNode[curr] != 0){
    //     pathTaken.push_back(curr);
    //     curr = prevNode[curr];
    // }

    return 0;
}

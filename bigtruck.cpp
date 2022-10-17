#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
/**
 * Additional layer on dijstra SSSP problem. Two things to sort -
 * 1. always pick shortest path
 * 2. implement second relax operation on total items taken along the path as well
 */
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

class node
{
public:
    int distance;
    int neighbour;
    int items;
};

class compare
{
public:
    bool operator()(const node &n1, const node &n2)
    {
        return ((n1.distance == n2.distance) ? (n1.items < n2.items) : (n1.distance > n2.distance));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in.txt" , "r", stdin);
    int n;
    cin >> n;

    vi items(n);

    for (auto &i : items)
    {
        cin >> i;
    }

    int m;
    cin >> m;

    vector<vii> AL(n, vii());

    while (m--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        AL[a - 1].emplace_back(b - 1, d); // undirected
        AL[b - 1].emplace_back(a - 1, d);
    }

    int s = 0; // source is 0;

    vi dist(n, INF);
    vi totalItem(n, 0);
    dist[s] = 0; // INF = 1e9 here
    totalItem[s] = items[s];

    // (Modified) Dijkstra's algorithm
    priority_queue<node, vector<node>, compare> pq; // sort by nodes
    pq.push({dist[s], s, totalItem[0]});

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty())
    { // main loop
        auto [d, u, itm] = pq.top();

        pq.pop(); // shortest unvisited u with more items

        if (d > dist[u]) continue;   // a very important check
        
        for (auto &[v, w] : AL[u])
        { // all edges from u
            if (dist[u] + w > dist[v]) continue;          // if greater distance, skip
            
            else if (dist[u] + w == dist[v]){     // if equal distance, relax items, queue node
                totalItem[v] = max(totalItem[u] + items[v], totalItem[v]);
                pq.push({dist[v], v, totalItem[v]});
                continue;
            }
            

            dist[v] = dist[u] + w; // relax operation, new dist is smaller than current distance to v
            totalItem[v] = totalItem[u] + items[v]; // have to take item of shorter path
            pq.push({dist[v], v, totalItem[v]}); // enqueue better node
        }
    }
    if(dist[n-1] == INF){
        cout << "impossible\n";
        return 0;
    }
    cout << dist[n-1] << " " << totalItem[n-1];
}

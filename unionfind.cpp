#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UFDS
{
private:
    vector<long> p, rank, setSize;
    long numSets;

public:
    UFDS(long N)
    {
        p.assign(N, 0);
        for(long i=0;i<N;i++){
            p[i]=i;
        }
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }
    long findSet(long x)
    {
        while (p[x] != x)
            x = p[x];
        return x;
    }
    bool isSameSet(long x, long y)
    {
        while (p[x] != x)
            x = p[x];
        while (p[y] != y)
            y = p[y];
        return (x == y);
    }

    long sizeofSet(long x)
    {
        return setSize[x];
    }
    long numofSets()
    {
        return numSets;
    }
    void unionSet(long x, long y)
    {
        long a = findSet(x), b = findSet(y);
        if (rank[a] > rank[b])
        {
            swap(a, b);
        }
        p[a] = b;
        if (rank[a] == rank[b])
        {
            rank[y]++;
        }
        setSize[b] += setSize[a]; // b is taller tree, join a under b
        numSets--;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long N, Q, a, b;
    char cmd;
    cin >> N >> Q;
    UFDS UF(N);
    while (Q)
    {
        cin >> cmd >> a >> b;
        if (cmd == '=')
        {
            UF.unionSet(a, b);
        }
        else if (cmd == '?')
        {
            if (UF.isSameSet(a, b))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
        Q--;
    }
    return 0;
}
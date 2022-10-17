#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;


class UFDS
{ // OOP style
private:
    vector<ll> p, setSize, sumSet; // vector<ll> p is the key part, newPar 
    ll numNodes;
public:
    UFDS(ll N)
    {
        p.assign(N+1, 0);
        sumSet.assign(N+1, 0);
        for (ll i = 0; i < N; ++i)
        {

            p[i] = i;
            sumSet[i] = 1 + i;
        }
        setSize.assign(N, 1); // optional feature
        numNodes = N;         // optional feature
    }

    ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    ll sizeOfSet(ll i) { return setSize[findSet(i)]; } // optional

    void unionSet(ll i, ll j)
    {
        ll x = findSet(i), y = findSet(j); // find both rep items
        if(x!=y){
            setSize[y] += setSize[x]; // combine set sizes at y
            sumSet[y] += sumSet[x];
            p[x] = y;       // set x under y
        }
    }

    void moveSet(ll x, ll y)
    {
       
    }

    ll sumOfSet(ll x) { return sumSet[findSet(x)]; }

    // wrapper functions
    void move(ll x, ll y){
        // moveSet(x-1,y-1);
    }
    void join(ll x, ll y){
        // unionSet(newPar[x-1],newPar[y-1]);
    }
    void status(ll x){
        // cout << sizeOfSet(newPar[x-1]) << " " << sumOfSet(newPar[x-1]) << "\n";
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // return 0;
    long N, T;
    // freopen("in.txt", "r", stdin);
    cin >> N >> T;
    UFDS UF(N);
    long c, x, y;
    while (T--)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> x >> y;
            UF.join(x,y);
        }
        else if (c == 2)
        {
            cin >> x >> y;
            UF.move(x,y);
        }
        else if (c == 3)
        {
            cin >> x;
            UF.status(x);
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;

#define INDEX (i * c + j)
#define UP ((i - 1) * c + j)
#define DOWN ((i + 1) * c + j)
#define LEFT (i * c + j - 1)
#define RIGHT ((i)*c + j + 1)

typedef vector<int> vi;

class UnionFind
{ // OOP style
private:
    vi p, height, setSize; // vi p is the key part
    vector<bool> validity;
    int numSets;
    int height;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
            cin >> height[i];
        setSize.assign(N, 1); // optional feature
        numSets = N;          // optional feature
        validity.assign(N, true);
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    bool isValid(int i) { return validity[i]; }
    int numDisjointSets() { return numSets; }            // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
    int sizeOfValidSet()
    {
        int count = 0;
        for (int i = 0; i < validity.size(); i++)
        {
            if (validity[i])
                count++;
        }
        return count;
    } // returns answer

    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;                         // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (height[x] > height[y])
            validity[x] = false;
        swap(x, y); // keep x 'shorter' than y
        p[x] = y;   // set x under y
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets;                // a union reduces numSets
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;
    auto ufds = UnionFind(r * c);

    for (int i = 1; i < r - 1; i++)
    {
        for (int j = 1; j < c - 1; j++)
        {
            ufds.unionSet(INDEX, UP);
            ufds.unionSet(INDEX, DOWN);
            ufds.unionSet(INDEX, LEFT);
            ufds.unionSet(INDEX, RIGHT);
        }
    }
    // edge cases to union join corners
    // top left
    ufds.unionSet(0,c); ufds.unionSet(0,1);
    // bottom left
    ufds.unionSet((r-1)*c,(r-2)*c); ufds.unionSet((r-1)*c,(r-1)*c+1);
    // top right
    ufds.unionSet((c-1),(c-2)); ufds.unionSet((c-1),(2*c-1));
    // bottom right
    ufds.unionSet((r*c-1),(r-1)*c-1); ufds.unionSet((r*c-1),r*c-2);

    cout << ufds.sizeOfValidSet();
    return 0;
}
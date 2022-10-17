#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <utility>
#include <string>

const int INF = 1e9;

/**
 * @brief
 * 
 * UPDATE: fixed it by checking initial position of the man...
 *  this shit is still not working for some reason?? floodfill/bfs type qn
 * main idea is to propogate fire and track at which time it will reach a square
 * then propogate teh man, valid moves are if he reaches a square before the fire does
 * public test cases all pass, failing private somewhere tbc...
 *
 */
using namespace std;
class building
{
private:
    int sizeR, sizeC;
    bool escaped = false;

    vector<vector<char>> grid;
    vector<vector<int>> trackFire; // tracks where the fire is at what second
    vector<vector<int>> trackMan;  // tracks when each square will be visited by man

    // queue for fire then man
    queue<pair<int, int>> qMan;
    queue<pair<int, int>> qFire;

    vector<pair<int, int>> nextMove = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    building(int c, int r)
    {
        sizeC = c;
        sizeR = r;
        grid.assign(r, vector<char>(c, '.'));
        trackMan.assign(r, vector<int>(c, INF));
        trackFire.assign(r, vector<int>(c, INF)); // mark all as unvisited by fire

        for (int i = 0; i < r; i++)
        {
            string row;
            cin >> row;
            for (int j = 0; j < c; j++)
            {
                grid[i][j] = row[j];
                if (row[j] == 'J')
                {
                    qMan.push({i, j});
                    trackMan[i][j] = 1; // time man reaches the square
                }
                if (row[j] == 'F')
                {
                    qFire.push({i, j});
                    trackFire[i][j] = 1; // time 1
                }
            }
        }
    }

    bool validMove(int nR, int nC) // check bounds, check not wall not fire // could be more efficient but move on
    {
        return ((nR < sizeR && nC < sizeC && nR >= 0 && nC >= 0) &&
                (grid[nR][nC] != '#' && grid[nR][nC] != 'F')); // check later to =='.'
    }

    bool border(int nR, int nC)
    {
        return (nR == sizeR - 1 || nC == sizeC - 1 || nR == 0 || nC == 0);
    }

    void printGrid() // debug
    {
        cout << "printing Grid\n";
        for (int i = 0; i < sizeR; i++)
        {
            for (int j = 0; j < sizeC; j++)
            {
                cout << grid[i][j] << "";
            }
            cout << "\n";
        }
    }
    void printTrackFire() // debug
    {
        cout << "printing fire's timepath\n";
        for (int i = 0; i < sizeR; i++)
        {
            for (int j = 0; j < sizeC; j++)
            {
                cout << ((trackFire[i][j]) ? (trackFire[i][j]) : trackFire[i][j]) << " ";
            }
            cout << "\n";
        }
    }
    void printTrackMan() // debug
    {
        cout << "printing man's timepath\n";
        for (int i = 0; i < sizeR; i++)
        {
            for (int j = 0; j < sizeC; j++)
            {
                cout << trackMan[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // bfs
    void solve()
    {
        auto [initR, initC] = qMan.front();
        if(border(initR, initC)){
            cout << "1\n";
            return;
        }
        // bfs fire first, find at which time where the fire is
        while (!qFire.empty())
        {
            auto [r, c] = qFire.front();
            qFire.pop();
            int currTime = trackFire[r][c];
            for (int i = 0; i < 4; i++)
            {
                int nR = r + nextMove[i].first;
                int nC = c + nextMove[i].second;
                if (validMove(nR, nC) && trackFire[nR][nC] == INF) // within bounds & unvisited by fire
                {
                    qFire.push({nR, nC});             // push frontier of bfs fire
                    trackFire[nR][nC] = currTime + 1; // track at which time fire will be at square
                }                                     // at the end of this, trackfire == 0 means unvisited by fire, 1 2 3 ...
            }
        }

        // printTrackFire();

        // bfs man
        while (!qMan.empty())
        {
            auto [r, c] = qMan.front();
            qMan.pop();
            int currTime = trackMan[r][c];
            for (int i = 0; i < 4; i++)
            {
                int nR = r + nextMove[i].first;
                int nC = c + nextMove[i].second;
                if (validMove(nR, nC) && trackMan[nR][nC] == INF) // unvisited by man and within bounds
                {
                    qMan.push({nR, nC});             // push valid frontier of man
                    trackMan[nR][nC] = currTime + 1; // track time visited by man

                    if (border(nR, nC) && trackMan[nR][nC] < trackFire[nR][nC])
                    {
                        escaped = true;
                        cout << trackMan[nR][nC] << "\n";
                        return;
                    }
                }
            }
        }

        // printTrackMan();

        if (!escaped)
        {
            cout << "IMPOSSIBLE\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in.txt", "r", stdin);

    int c, r;

    cin >> r >> c;
    building b(c, r);
    b.solve();

    return 0;
}

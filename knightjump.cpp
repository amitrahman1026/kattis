#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class board
{
private:
    int size;
    int startR, startC;

    vector<vector<char>> grid;
    vector<vector<int>> distance;

    queue<pair<int, int>> q;

    vector<pair<int, int>> nextMove = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

public:
    board(int n)
    {
        size = n;
        grid.assign(n, vector<char>(n,'.'));
        distance.assign(n, vector<int>(n,-1));

        string row;
        for (int r = 0; r < n; r++)
        {
            cin >> row;
            for (int c = 0; c < n; c++)
            {
                grid[r][c] = row[c];
                if (row[c] == 'K')
                {
                    startC = c;
                    startR = r;
                    distance[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
    }

    bool isValidMove(int nR, int nC)
    {
        return (nR < size && nC < size && nR >= 0 && nC >= 0);
    }


    void printGrid()
    {
        cout << "printing Grid";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void printDistance()
    {
        cout << "printing Distance";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << distance[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // bfs
    void solve()
    {
        while(!q.empty()){
            auto &[r,c] = q.front();
            if(r == 0 && c == 0) break;
            q.pop();
            for(int i = 0; i<8; i++){
                int nR = r + nextMove[i].first;
                int nC = c + nextMove[i].second;

                if(isValidMove(nR,nC)){
                    if(grid[nR][nC] == '#' || distance[nR][nC] != -1) continue;
                    q.push({nR,nC});
                    distance[nR][nC] = distance[r][c] + 1;
                    // printDistance();
                    // printGrid();
                }
            }
        }
        cout << distance[0][0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen ("in.txt","r",stdin);
    // init grid & distance
    int n;
    cin >> n;
    board b(n);
    b.solve();
    // bfs of coordinates of grid

    return 0;
}

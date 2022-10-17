#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int rank = 25, streak = 0, stars = 0;
    string s;
    cin >> s;
    vector<int> rank_star;
    for (int i = 0; i < 10; i++)
        rank_star.push_back(5);
    for (int i = 0; i < 5; i++)
        rank_star.push_back(4);
    for (int i = 0; i < 5; i++)
        rank_star.push_back(3);
    for (int i = 0; i < 5; i++)
        rank_star.push_back(2);

    // for(auto &i : rank_star) cout << i;

    for (int i = 0; i < s.length(); i++)
    {
        // process game result
        if (s[i] == 'W')
        {
            streak++;
            stars += (streak > 2 && rank > 5) ? 2 : 1; // rank  6-25 and streak>=3, bonus star
            if (stars > rank_star[rank - 1])
            {
                stars = stars - rank_star[rank - 1];
                rank--;
                if (!rank)
                {
                    cout << "Legend";
                    return 0;
                }
            }
        }
        else if (s[i] == 'L')
        {
            streak = 0;

            if (rank > 20)
                continue; // no stars lost if rank 21-25
            stars--;      // rank 1 - 20 loses star
            if (stars < 0)
            {
                if (rank == 20) // can't drop below rank 20
                {
                    stars = 0;
                    continue;
                } 
                rank++; // else drop rank
                stars = rank_star[rank - 1] - 1;
            }
        }
    }
    cout << rank;
}
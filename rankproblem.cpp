#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> ranking(n);
  iota(ranking.begin(), ranking.end(), 1);

  // for(auto i:ranking){
  //   cout << i;
  // }

  for (long iter = 0; iter < m; iter++)
  {
    char a, b;
    int i, j;
    cin >> a >> i >> b >> j;
    int winner = find(ranking.begin(), ranking.end(), i) - ranking.begin();

    int loser = find(ranking.begin(), ranking.end(), j) - ranking.begin();
    cout << loser;
    if (winner < loser)
    {
      ranking.erase(ranking.begin() + loser);
      ranking.insert(ranking.begin() + winner, loser);
    }
  }

  for (auto &r_i : ranking) // output the final ranking
    cout << 'T' << r_i << ' ';
  cout << '\n';

  return 0;
}

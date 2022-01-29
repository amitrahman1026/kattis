#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> ranking(n);
  iota(ranking.begin(), ranking.end(), 0); // 1, 2, 3, ..., N
  while (m--) { // repeat m times, one for each of the m matches
    char dummy1, dummy2; int i, j; cin >> dummy1 >> i >> dummy2 >> j; // team i beats team j
    int idx_i = find(ranking.begin(), ranking.end(), i) - ranking.begin(); // we will get the index of value i at the moment (inside ranking vector)
    int idx_j = find(ranking.begin(), ranking.end(), j) - ranking.begin();
    if (idx_i < idx_j) { // the order is wrong, we need to re-ranking
      ranking.erase(ranking.begin() + idx_j); // erase Tj first (the beaten one) from the ranking
      ranking.insert(ranking.begin() + idx_i, j); // insert j at previous idx_i
    }
  }

  for (auto& r_i : ranking) // output the final ranking
    cout << 'T' << r_i << ' ';
  cout << '\n';

  return 0;
}

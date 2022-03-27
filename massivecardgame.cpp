#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long N, input, l, r;
    cin >> N;
    std::vector<long> v;
    for (long i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    cin >> N;
    for (long i = 0; i < N; i++)
    {
        cin >> l >> r;
        auto l_low = lower_bound(v.begin(), v.end(), l);
        auto r_upp = upper_bound(v.begin(), v.end(), r);
        long count = 0;
        count = r_upp - l_low;
        cout << count << '\n';
    }
    return 0;
}
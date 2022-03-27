/**
 * @file Problem_A_-_Doctor_Kattis.cpp
 * @author Amit Rahman A0244348B
 *
 */

#include <iostream>
#include <string>
#include <utility>
#include <map>
using namespace std;

struct comp
{
    template <typename T>
    bool operator()(const T &l, const T &r) const
    {
        if (l.first == r.first)
        {
            return l.second < r.second;
        }
        return l.first > r.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long infectionLevel, updateInfectionLevel, command, N, entryTime = 0, inf, time;
    pair<long, long> temp;
    string catName;
    cin >> N;

    // max query
    map<pair<long, long>, string, comp> maxQuery;
    auto it = maxQuery.begin();
    // lookup
    map<string, pair<long, long>> lookup;

    for (long i = 0; i < N; i++)
    {
        cin >> command;
        switch (command)
        {
        // ArriveAtClinic
        case 0:
            cin >> catName >> infectionLevel;
            entryTime++;
            // pair <infectionLevel, entryTime>
            temp = make_pair(infectionLevel, entryTime);
            lookup.insert({catName, temp});
            maxQuery.insert({temp, catName}); // add in lambda function to compare temp

            break;
        // UpdateInfectionLevel
        case 1:
            cin >> catName >> updateInfectionLevel;

            inf = lookup[catName].first;
            time = lookup[catName].second;
            // update maxQuery
            maxQuery.erase({inf, time});
            maxQuery.insert({{inf + updateInfectionLevel, time}, catName});
            // update lookup
            lookup[catName].first += updateInfectionLevel;
            break;
        // Treated
        case 2:
            cin >> catName;
            inf = lookup[catName].first;
            time = lookup[catName].second;

            maxQuery.erase({inf, time});
            lookup.erase(catName);

            break;
        // Query
        case 3:
            // iterate for largest priority
            //   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            //     std::cout << it->first << " => " << it->second << '\n';
            if (maxQuery.empty())
            {
                cout << "The clinic is empty\n";
                break;
            }
            it = maxQuery.begin();
            cout << it->second << "\n";
            break;

        default:
            break;
        }
    }
}

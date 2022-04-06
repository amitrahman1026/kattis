// PL2_4M4R
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long N, Q;
    string s, a, b;
    cin >> N >> Q;
    list<string>l;
    unordered_map<string,string> partner;

    for (long i = 0; i < N; i++)
    {
        cin >> a >> b;
        l.push_back(a); l.push_back(b);
        partner.insert({a,b}); partner.insert({b,a});
    }
    cin >> s;
    auto j = l.begin();

    for (long i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'F')
        {
            j--; 
        }
        else if (s.at(i) == 'B')
        {
            j++;
        }
        else if(s.at(i) == 'R'){
            if(j == --l.end()){
                j=l.begin();
            }
            else{
                string temp = *j;
                j++; 
                l.remove(temp);
                l.push_back(temp);
            }
        }
        else if(s.at(i) == 'C'){
            auto pos_partner = find(l.begin(),l.end(),partner[*j]);
            pos_partner++;
            string temp = *j;
            if(j == --l.end()){
                j=l.begin();
            } else {
                j++;
            }            
            l.remove(temp);
            l.insert(pos_partner,temp);
        }
        else if (s.at(i) == 'P')
        {
            cout << partner[*j] << '\n';
        }
    }
    cout << '\n';

    for (auto &i:l){
        cout << i << '\n';
    }
   
}
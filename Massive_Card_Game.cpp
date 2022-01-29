#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long N, temp, Q, l, r;
    cin >> N;
    vector<long> cards(N);
    
    for(long i=0; i<N;i++){
        cin >> temp;
        cards.push_back(temp);
    }
    sort(cards.begin(), cards.end());

    cin >> Q;
    for (long i=0;i<Q;i++){
        long out=0;
        cin >> l >> r;
        lower_bound(cards.begin(),cards.end(), l) - cards.begin();
        
        cout << out<<'\n';
    }

}

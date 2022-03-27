#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> threewaypartition(int a[], int lo, int hi)
{
    int p = a[lo];        // p = a[lo] (first index in [lo..hi]) is always the pivot
    int st, en; // overwrite this with your answer

    int i = 0;
    int j = 0;
    int k = hi;

    while(j <= k){
        if(a[j] < p){
            swap(a[i], a[j]);
            i = j +1;
            j++;
        }
        else if(a[j] > p){
            swap(a[j],a[k]);
            k--;

        }
        else{
            j++;
        }
    }
    st = i; en = j;
    return {st, en}; // return st/en ind(ices) of a that are == pivot as a pair
}

int main()
{
}


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    vector<int> arr(n);
    arr[0] = 1;
    for (int i=0;i<n-1;i++){
        cin >> temp;
        arr[temp + 1] = i + 2;
    }
    for(int i = 0 ; i < n; i++){
        cout << arr[i] << " ";
    }
}

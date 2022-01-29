#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long N, t;
    cin >> N >> t;
    vector<long> A(N);
    for (long i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    // for(long i = 0; i < N; i++){
    //     cout<< A[i] << " ";
    // }
    // for (long i = 0; i < N; i++)
    long l = 0, r = N - 1;      // case 1
    long count = 1, number = 0; // case 3

    switch (t)
    {
    case 1:
        while (l < r)
        {
            if (A[l] + A[r] == 7777)
            {
                cout << "Yes\n";
                return 0;
            }
            else if (A[l] + A[r] < 7777)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        cout << "No\n";
        break;
    case 2:
        for (long i = 0; i < N - 1; i++)
        {
            if (A[i] == A[i + 1])
            {
                cout << "Contains duplicate\n";
                return 0;
            }
        }
        cout << "Unique\n";
        break;
    case 3:
        for (int j = 1; j < N; j++)
        {
            if (count > N / 2)
            {
                cout << number << "\n";
                return 0;
            }
            if (A[j] == A[j - 1])
            {
                count++;
                number = A[j];
            }
            else
            {
                count = 1;
            }
        }
        cout << -1 << "\n";
        break;
    case 4:
        if (N % 2 == 1)
        {
            cout << A[N / 2] << endl;
        }
        else
        {
            cout << A[N / 2 - 1] << " " << A[N / 2] << endl;
        }
        break;
    case 5:
        for (int i = 0; i < N; i++)
        {
            if (A[i] < 100 || A[i] > 999)
            {
                continue;
            }
            cout << A[i] << " ";
        }
        cout << endl;
        break;

    default:
        break;
    }
    return 0;
}

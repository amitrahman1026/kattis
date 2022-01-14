#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long N, t;
    cin >> N >> t;
    vector<long> A(N);
    vector<int> B(N);
    B = {0};
    for (long i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    switch (t)
    {
    case 1:
        cout << 7 << "\n";
        break;
    case 2:
        if (A[0] > A[1])
        {
            cout << "Bigger" << endl;
        }
        else if (A[0] == A[1])
        {
            cout << "Equal" << endl;
        }
        else
        {
            cout << "Smaller" << endl;
        }
        break;
    case 3:
        long median;
        median = max(min(A[0], A[1]), min(max(A[0], A[1]), A[2]));
        cout << median << endl;
        break;
    case 4:
        long sum;
        sum = 0;
        for (long i = 0; i < N; i++)
        {
            sum += A[i];
        }
        cout << sum << endl;
        break;
    case 5:
        sum = 0;
        for (long i = 0; i < N; i++)
        {
            if (A[i] % 2 == 0)
            {
                sum += A[i];
            }
        }
        cout << sum << endl;
        break;
    case 6:
        char c;
        for (long i = 0; i < N; i++)
        {
            A[i] = (A[i] % 26);
            c = 'a' + A[i];
            cout << c;
        }
        cout << endl;
        break;
    case 7:
        long i;
        i = 0;
        while (i >= 0 && i < N)
        {
            i = A[i];
            if (B[i] > 2)
            {
                cout << "Cyclic" << endl;
                return 0;
            }
            if (i == N - 1)
            {
                cout << "Done" << endl;
                return 0;
            }
            B[i]++;
        }
        cout << "Out" << endl;
    default:
        break;
    }

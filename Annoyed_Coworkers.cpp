#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    long a, d, c, h, sum = 0, initial_a = 0;
    priority_queue<long> pq;
    cin >> h >> c;
    for (long i = 0; i < h; i++)
    {
        cin >> a >> d;
        initial_a += a;
    }
}



// User defined class, coworker
class coworker
{
private:
    long a;
    long d;

public:
    coworker(const long a_in, const long d_in)
    {
        a = a_in, d = d_in;
    }

    // void read(){
    //     cin >> a >> d;
    // }
    
    long SimAddAD() const
    {
        return a + d;
    }
    
    long AddAD()
    {
        return a + d;
    }

    long getA() const
    {
        return a;
    }

    long getD() const
    {
        return d;
    }
};
// // compare two coworkers possible a + d values
// struct MinSort
// {
//     bool operator()(const CoworkerT &p1, const CoworkerT &p2) const
//     {
//         return p1.SimAddAD() < p2.SimAddAD();
//     }
// };

// // // compare two coworkers possible a + d values ~for some reason heap lesser than or greater need to be reverse of operator for sort???
// bool Min
// {
//     bool operator()(const CoworkerT &p1, const CoworkerT &p2) const
//     {
//         return p1.SimAddAD() > p2.SimAddAD();
//     }
// };

// // compare two a values between coworkers
// struct MaxSort
// {
//     bool operator()(const CoworkerT &p1, const CoworkerT &p2) const
//     {
//         return p1.getA() > p2.getA();
//     }
// };

// void FindAndPrintMax(vector<CoworkerT> &max)
// {
//     sort(max.begin(), max.end(), MaxSort());
//     CoworkerT minMax = max.front();
//     cout << minMax.getA();
// }

// void InputCoworkersAD(vector<CoworkerT> &min, long &h, long &c)
// {
//     int a, d, i;
//     cin >> h >> c;
//     // Insert a and d into the vector
//     if (h <= 100000 && h >= 1 && c <= 100000 && c >= 1)
//     {
//         for (i = 0; i < c; i++)
//         {
//             cin >> a >> d;
//             min.push_back(CoworkerT(a, d));
//         }
//     }
//     make_heap(min.begin(), min.end(), Min());
// }

// void AskForHelp(vector<CoworkerT> &min, long h)
// {
//     int i = 0;

//     while (i < h)
//     {
//         push_heap(min.begin(), min.end(), Min());
//         CoworkerT e = min.front();
//         pop_heap(min.begin(), min.end(), Min());
//         min.pop_back();
//         min.push_back(CoworkerT(e.AddAD(), e.getD()));
//         i++;
//     }
// }

// Driver code
int main()
{
    long h, c;
    vector<coworker> min;

    long a, d;
    
    for(long i=0; i < c; i++){
        // new coworker;
        cin >> a >> d;
        min.push_back(coworker(a, d));

    }
    //make_heap

    for(long i=0; i<h;i++){
        //pop_heap(vector.begin,vector.end, bool min)
    }



    return 0;
}
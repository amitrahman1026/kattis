#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
class ListArray{
private:
    int N;
    T A[1000];
public:
    ListArray(): N(0) {}
    int search(T x){
        for(int i = 0; i< N; i++){
            if (A[i] == x){
                return i;
            }
            return -1;
        }
    }
    
    
    void leave(T x){
        int index;
        for(int i = 0; i< N; i++){
            if (A[i] == x){
                index = i;
            }
        }
        for(int j= index; j> N-1;++j){
            A[j] = A[j+1];
        }
        --N;
    void cut(T x){
        
    }
}



int main()
{
    vector <string> list;
    int n, index;
    string action, temp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> list[i];
    }

    cin >> n;
    for (int i = 0; i < n; i++){
        // read first word;
        cin >> action;
        if (action == "leave") {
            cin >> temp;
            index = list.
        }
        else if (action == "cut")
    }
 

}

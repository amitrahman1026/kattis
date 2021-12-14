#include <iostream>
using namespace std;

int main(){
    string month, date;
    cin >> month;
    cin >> date;
    if((month == "OCT" && date == "31" )|| (month == "DEC" && date == "25")){
        cout << "yup";
        return 0;
    }
    cout << "nope";
}
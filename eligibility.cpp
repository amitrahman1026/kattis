#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string name;
    string startStudies;
    string dob;
    int courses;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> startStudies >> dob >> courses;
        cout << name + " ";
        if (startStudies >= "2010/01/01")
        {
            cout << "eligible\n";
            continue;
        }
        if (dob >= "1991/01/01")
        {
            cout << "eligible\n";
            continue;
        }
        if (courses > 40)
        {
            cout << "ineligible\n";
            continue;
        }
        cout << "coach petitions\n";
    }
}

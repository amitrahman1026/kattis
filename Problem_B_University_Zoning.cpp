#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool facultySort(const pair<long, long> &a, const pair<long, long> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

bool studentSort(const pair<long, pair<long, long>> &a, const pair<long, pair<long, long>> &b)
{
    return a.first < b.first;
}

int main()
{
    // 1st line
    long R_row, C_col;
    long F_numFacs;
    long S_numStudents;
    long G_minCompliantFacs;

    cin >> R_row >> C_col >> F_numFacs >> S_numStudents >> G_minCompliantFacs;

    // next F lines
    long K_numCellsInFacs;
    long Rk_facRow, Ck_facCol;
    vector<vector<pair<long, long>>> faculty;

    for (long id = 1; id <= F_numFacs; id++)
    {
        cin >> K_numCellsInFacs;
        vector<pair<long, long>> facCoordinates;

        for (long i = 0; i < K_numCellsInFacs; i++)
        {
            cin >> Rk_facRow >> Ck_facCol;
            facCoordinates.push_back(make_pair(Rk_facRow, Ck_facCol));
        }
        // sort facCoordinates, then push back sorted list
        sort(facCoordinates.begin(), facCoordinates.end(), facultySort);
        faculty.push_back(facCoordinates);
    } // 2d vector of all cells occupied by each faculty with sorted coordinatinates <row,col>
    // next S lines
    long Rs_studentRowInit, Cs_studentColInit, D_studentID, f_studentFac;
    vector<vector<pair<long, pair<long, long>>>> studentData(F_numFacs); // push back student data according to their faculty;
    for (long i = 0; i < S_numStudents; i++)
    {
        cin >> Rs_studentRowInit >> Cs_studentColInit >> D_studentID >> f_studentFac;
        pair<long, pair<long, long>> temp;
        temp = make_pair(D_studentID, make_pair(Rs_studentRowInit, Cs_studentColInit));
        studentData[f_studentFac - 1].push_back(temp);
    }
    // sort students
    for (long i = 0; i < F_numFacs; i++)
    {
        sort(studentData[i].begin(), studentData[i].end(), studentSort);
    }
    // manhattan distance
    long manhattanDist;
    vector<vector<long>> manDistByFac(F_numFacs);

    for (int i = 0; i < F_numFacs; i++)
    {
        for (int j = 0; j < studentData[i].size(); j++)
        {
            manhattanDist = abs(faculty[i][j].first - studentData[i][j].second.first) + abs(faculty[i][j].second - studentData[i][j].second.second);
            manDistByFac[i].push_back(manhattanDist);
        }
    }

    for (long i = 0; i < F_numFacs; i++)
    {
        sort(manDistByFac[i].begin(), manDistByFac[i].end());
    }

    vector<long> stepsToCompliance;
    // last line, F number of T values
    long T_facMinStudent;
    for (long i = 0; i < F_numFacs; i++)
    {
        cin >> T_facMinStudent;
        long temp = 0;
        for (long j = 0; j < T_facMinStudent; j++)
        {
            temp += manDistByFac[i][j];
        }
        stepsToCompliance.push_back(temp);
    }
    // sort lowest steps for full compliant facs
    sort(stepsToCompliance.begin(), stepsToCompliance.end());

    long steps = 0;
    for (long i = 0; i < G_minCompliantFacs; i++)
    {
        steps += stepsToCompliance[i];
    }
    cout << steps << endl;
}
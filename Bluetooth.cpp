#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string tooth, condition;
    bool trackLower[16];
    bool trackUpper[16];
    for (int i = 0; i < 16; i++)
    {
        trackLower[i] = true;
        trackUpper[i] = true;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tooth >> condition;
        int index;

        // left lower
        if (tooth[0] == '-')
        {
            index = (int)(tooth[1] - '0');
            index = 8 - index;
            if (condition == "m")
            {
                trackLower[index] = false;
            }
            if (condition == "b")
            {
                for (int i = 0; i < 8; i++)
                {
                    trackLower[i] = false;
                }
            }
        }
        // left upper
        else if (tooth[0] == '+')
        {
            index = (int)(tooth[1] - '0');
            index = 8 - index;
            if (condition == "m")
            {
                trackUpper[index] = false;
            }
            if (condition == "b")
            {
                for (int i = 0; i < 8; i++)
                {
                    trackLower[i] = false;
                }
            }
        }
        // right lower
        else if (tooth[1] == '-')
        {
            index = (int)(tooth[0] - '0');
            index += 7;
            if (condition == "m")
            {
                trackLower[index] = false;
            }
            if (condition == "b")
            {
                for (int i = 8; i < 16; i++)
                {
                    trackLower[i] = false;
                }
            }
        }
        // right upper
        else if (tooth[1] == '+')
        {
            index = (int)(tooth[0] - '0');
            index += 7;
            if (condition == "m")
            {
                trackUpper[index] = false;
            }
            if (condition == "b")
            {
                for (int i = 8; i < 16; i++)
                {
                    trackUpper[i] = false;
                }
            }
        }
    }
    int leftLower = 0;
    int leftUpper = 0;
    int rightLower = 0;
    int rightUpper = 0;

    for (int i = 0; i < 8; i++)
    {
        if (trackLower[i])
        {
            leftLower++;
        }
        if (trackUpper[i])
        {
            leftUpper++;
        }
    }

    for (int i = 8; i < 16; i++)
    {
        if (trackLower[i])
        {
            rightLower++;
        }
        if (trackUpper[i])
        {
            rightUpper++;
        }
    }

    if (leftLower > 0 && leftUpper > 0)
    {
        cout << 0;
    }
    else if (rightLower > 0 && rightUpper > 0)
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }

    return 0;
}
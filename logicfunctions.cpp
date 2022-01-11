#include "logicfunctions.h"

// Compute xor
void exclusive(bool x, bool y, bool &ans)
{
    if (x == true)
    {
        if (y == true)
        {
            ans = false;
        }
        else
        {
            ans = true;
        }
    }
    else if (y == true)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
}

// Compute implication
void implies(bool x, bool y, bool &ans)
{
    if (x == true)
    {
        if (y == true)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    else if (y == true)
    {
        ans = true;
    }
    else
    {
        ans = true;
    }
}

// Compute equivalence
void equivalence(bool x, bool y, bool &ans)
{
    if (x == true)
    {
        if (y == true)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    else if (y == true)
    {
        ans = false;
    }
    else
    {
        ans = true;
    }
}
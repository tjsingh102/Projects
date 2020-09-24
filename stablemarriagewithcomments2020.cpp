
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool ok(int q[], int c)
{

    static int mp[3][3] = {0, 2, 1,
                           0, 2, 1,
                           1, 2, 0};

    static int wp[3][3] = {2, 1, 0,
                           0, 1, 2,
                           2, 0, 1};

    for (int i = 0; i < c; i++)
    {
        if (q[c] == q[i])
            return false;
    }

    for (int i = 0; i < c; i++)
    {
        if ((mp[c][q[i]] < mp[c][q[c]]) && (wp[q[i]][c] < wp[q[i]][i]))
        {

            return false;
        }
        if ((wp[q[c]][i] < wp[q[c]][c]) && (mp[i][q[c]] < mp[i][q[i]]))
        {

            return false;
        }
    }

    return true;
}
void print(int q[])
{
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; ++i)
        cout << i << "\t" << q[i] << "\n";
    cout << "\n";
}
void backtrack(int &c)
{
    c--; // Go back to the previous column
    if (c < 0)
    {
        exit(0);
    }
}
int main()
{
    int q[3] = {};
    q[0] = 0;
    int c = 0;

    while (c >= 0)
    {
        // End the loop if you backtrack from the first column
        c++; // Move to the next column
        if (c > 2)
        { // If you have passed the last column,
            print(q);
            backtrack(c);
        } // Call the print function and backtrack
        else
        {
            q[c] = -1;
        } // Otherwise, move to one before the first row
        while (c >= 0)
        {
            q[c]++; // Move to the next row
            if (q[c] > 2)
            {
                q[c] = -1;
                backtrack(c);
            } // If you have passed the end of the column, backtrack
            else if (ok(q, c))
            {
                break;
            } // Otherwise, call the ok function. If it returns
              //true, go back to the beginning of the outer loop.
        }

        if (c == -1)
        {
            break;
        }
    }
    return 0;
}
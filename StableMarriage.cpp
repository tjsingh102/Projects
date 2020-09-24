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
    c--; 
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
        
        c++; 
        if (c > 2)
        { 
            print(q);
            backtrack(c);
        } 
        else
        {
            q[c] = -1;
        } 
        while (c >= 0)
        {
            q[c]++; 
            if (q[c] > 2)
            {
                q[c] = -1;
                backtrack(c);
            } 
            else if (ok(q, c))
            {
                break;
            } 
              
        }

        if (c == -1)
        {
            break;
        }
    }
    return 0;
}
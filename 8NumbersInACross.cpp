#include <iostream>
#include <cmath>
using namespace std;

void backtrack(int &c)
{
    c--;
    if (c == -1)
    {
        exit(1);
    }
}

void print(int q[], int c)
{
    int static solution = 1;
    cout << "Solution #" << solution << endl;
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl;
    cout << endl;
    solution++;
}

bool ok(int a[8],int c, int b)
{
    for (int i = 0; i < b; i++)
    {
        if (a[i] == a[c] || (abs(a[c] - a[b]) == 1))
            return false;
    }
    return true;
}

int main()
{
    int q[8] = {0}, c = 0, i = 0, count = 0;
    int static adjacent_table[8][5] =
        {{-1},
         {0, -1},
         {1, -1},
         {0, 1, 2, -1},
         {1, 2, 3, -1},
         {2, 4, -1},
         {0, 3, 4, -1},
         {3, 4, 5, 6, -1}};

    while (true)
    {
        while (c < 8)
        {
            q[c]++;
            if (q[c] > 8)
            {
                q[c] = 0;
                backtrack(c);
                continue;
            }
            for (i = 0; i < 5; i++)
            {
                if (adjacent_table[c][i] == -1)
                {
                    c++;
                    if (c == 8)
                    {
                        print(q, ++count);
                        backtrack(c);
                    }
                    break;
                }
                if (ok(q, c, adjacent_table[c][i]) == false)
                    break;
            }
        }
    }
}

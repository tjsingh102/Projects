#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c)
{
    static int helper[8][5] =
        {
            {-1},            // 0
            {0, -1},         // 1
            {1, -1},         // 2
            {0, 1, 2, -1},   // 3
            {1, 2, 3, -1},   // 4
            {2, 4, -1},      // 5
            {0, 3, 4, -1},   // 6
            {3, 4, 5, 6, -1} // 7
        };

    for (int i = 0; i < c; i++)
    {
        if (q[c] == q[i])
            return false;
    }

    int i = 0;
    while (helper[c][i] != -1)
    {
        if ((abs(q[c] - q[helper[c][i]])) == 1)
        {
            return false;
        }
        i++;
    }

    return true;
}

void print(int q[])
{
    static int solution = 1;
    cout << "Solution #" << solution << endl;
    cout << " " << q[1] << q[2] << endl;
    cout << q[0] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl;
    cout << endl;
    solution++;
}

int main()
{
    int q[8] = {}, c = 0, i = 0;
    q[c] = 1;

    while (c >= 0)
    {

        c++;
        if (c > 7)
        {
            print(q);
            c--;
        }

        while (c >= 0)
        {
            q[c]++;
            if (q[c] > 8)
            {
                q[c] = 0;
                c--;
            }
            else if (ok(q, c))
            {
                break;
            }
        }
    }
    return 0;
}

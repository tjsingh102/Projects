#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c)
{
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

void print(int q[])
{
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];
   box bb, wb;
   static box *board[8][8];

   for (i = 0; i < 5; i++)
      for (j = 0; j < 7; j++)
      {
         bb[i][j] = ' ';
         wb[i][j] = char(219);
      }

   static box bq = {{char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
                    {char(219), ' ', char(219), ' ', char(219), ' ', char(219)},
                    {char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
                    {char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
                    {char(219), char(219), char(219), char(219), char(219), char(219), char(219)}};

   static box wq = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', char(219), ' ', char(219), ' ', char(219), ' '},
                    {' ', char(219), char(219), char(219), char(219), char(219), ' '},
                    {' ', char(219), char(219), char(219), char(219), char(219), ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

   for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++)
         if ((i + j) % 2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;

   cout << "Solution #" << ++solution << ":\n ";

   for (int i = 0; i < 8; i++)
   {
      if (board[q[i]][i] == &wb)
         board[q[i]][i] = &bq;
      if (board[q[i]][i] == &bb)
         board[q[i]][i] = &wq;
   }

   for (i = 0; i < 7 * 8; i++)
      cout << '_';
   cout << "\n";

   for (i = 0; i < 8; i++)
      for (k = 0; k < 5; k++)
      {
         cout << char(179);
         for (j = 0; j < 8; j++)
            for (l = 0; l < 7; l++)

               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

   cout << " ";
   for (i = 0; i < 7 * 8; i++)
      cout << char(196);
   cout << "\n\n";

   for (int i = 0; i < 8; i++)
      if ((q[i] + i) % 2 == 0)
         board[q[i]][i] == &wq;
      else
         board[q[i]][i] == &bq;
}
int main()
{
   int q[8] = {}, c = 0;
   q[0] = 0;

   while (c >= 0)
   {
      c++;
      if (c == 8)
      {
         print(q);
         c--;
      }
      else
      {
         q[c] = -1;
      }
      while (c >= 0)
      {
         q[c]++;
         if (q[c] == 8)
         {
            c--;
         }
         else
         {
            if (ok(q, c))
               break;
         }
      }
   }

   return 0;
}

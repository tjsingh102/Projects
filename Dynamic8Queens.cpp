#include <iostream>
using namespace std;

bool Ok(int q[], int c) {
     for (int i = 0; i < c; i++) {
       if (q[i] == q[c] || c - i == abs(q[c] - q[i]))
         return false;
     }
         return true;
   }

int nqueens(int n) {

   int* q = new int[n];
   q[0] = 0;

   int c = 0, count = 0;

   while (c >= 0){
                
      c++;
      if(c > n){
         count ++;
         c--;
       
      }
      else
         q[c] = -1;

      while (c >= 0) {
         q[c]++;
                        
         if(q[c] > n){
            c --;
    
         }

         else if(Ok(q,c)){
            break;
         }
      }
   }
   
        delete [] q;
  
        return count;
}
int main(){
       int n = 8;
       for (int i = 0; i < n; ++i)
           cout << "There are " << nqueens(i) << " solutions to the " << i+1 << " queens problem" << endl;
       return 0;
    }
         


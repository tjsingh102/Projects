#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b){
    if(a.length()<b.length())
        swap(a,b);
    
    string answer = "";
    int i = (int)a.length() - 1;
    int j = (int)b.length() - 1;
    
    int carry = 0;
    int curr;
        while(i>=0) { 
            if(j>=0)
                curr = a[i] - '0' + b[j] - '0' + carry; 
            else
                curr = a[i] - '0' + carry;
        
            carry = curr / 10;
            curr = curr % 10;
            answer= to_string(curr) + answer;
            
            i--;
            j--;
            
    }
    if(carry == 1)
        answer = "1" + answer;
    return answer;
}


int main(){
    string a,b;
    while(true){
        cout << "enter two numbers a and b" << endl << "enter a: ";
            cin >> a;
        if(a == "done")
            return 0;
        else
            cout << "enter b:";
                cin >> b;
        cout << add(a,b);
    }
    }



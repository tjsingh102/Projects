#include <iostream>
#include <cmath>
using namespace std;

class Rat
{
private:
    int n;
    int d;

public:
    Rat()
    {
        n = 0;
        d = 1;
    }

    Rat(int i, int j)
    {
        n = i;
        d = j;
    }

    Rat(int i)
    {
        n = i;
        d = 1;
    }

    int getN() { return n; }
    int getD() { return d; }

    void setN(int i) { n = i; }
    void setD(int i) { d = i; }

    //arithmetic operators
    Rat operator+(Rat r)
    {
        Rat t;
        t.n = n * r.d + d * r.n;
        t.d = d * r.d;
        return t;
    }

    Rat operator-(Rat r)
    {
        Rat t;
        t.n = n * r.d - d * r.n;
        t.d = d * r.d;
        return t;
    }

    Rat operator*(Rat r)
    {
        Rat t;
        t.n = n * r.n;
        t.d = d * r.d;
        return t;
    }

    Rat operator/(Rat r)
    {
        Rat t;
        t.n = n * r.d;
        t.d = d * r.n;
        return t;
    }

    void reducer()
    {
        int greatestcd = gcd(n, d);

        setN(n / greatestcd);
        setD(d / greatestcd);
    }

    int gcd(int n, int d)
    {
        if (d == 0)
        {
            return n;
        }
        else
        {
            return gcd(d, n % d);
        }
    }

    friend ostream &operator<<(ostream &os, Rat r);
    friend istream &operator>>(istream &is, Rat &r);
};
ostream &operator<<(ostream &os, Rat r)
{

    r.reducer();

    if (r.n > r.d)
    {
        if (r.d != 1)
        {
            int a = r.n / r.d;
            int b = r.n % r.d;
            os << a << " " << b << "/" << r.d;
        }

        else
        { 
            os << r.n;
        }
    }

    else if (r.n == r.d)
    {
        os << 1;
    }

    else
    {
        if (r.n == 0)
        {
            os << 0;
        }

        else
        {

            os << r.n << "/" << r.d << endl;
        }
    }

    return os;
}

istream &operator>>(istream &is, Rat &r)
{
    is >> r.n >> r.d;
    return is;
}

int main()
{
    Rat r1(5, 2), r2(3, 2);

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;

    r1 = r2;
    r2 = r1 * r2;

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;

    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;

    return 0;
}

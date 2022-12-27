#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int temp;
    if(b > a)
    {
        temp = b;
        b = a;
        a = temp;
    }
    if(b == 0)
    {
        return a;
    }
    else
    {
        temp = a % b;
        return gcd(b,temp);
    }
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b);
}
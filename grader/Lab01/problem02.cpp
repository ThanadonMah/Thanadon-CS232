#include <iostream>

using namespace std;

int findRoot(int n)
{
    int i = 0;
    while(i*i < n){
        i++;
    }
    if(i*i == n){
        return i;
    }
    else{
        return i-1;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << findRoot(n);
}
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    string n,m;
    getline(cin,n);
    getline(cin,m);

    bool check[m.length()];
    for(int i = 0 ; i < m.length() ; i++)
    {
        check[i] = true;
    }

    for(int i = 0; i < n.length() ; i++)
    {
        for(int j = 0 ; j < m.length() ; j++)
        {
            if(n[i] != ' ')
            {
                if(n[i] == m[j] && check[j])
                {
                    cout << n[i] << ' ';
                    check[j] = false;
                    break;
                }
            }
            
        }
    }
}
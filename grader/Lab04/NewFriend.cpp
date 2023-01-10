#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    int n, j = 1;
    string l;
    getline(cin,l);
    n = stoi(l);
    int arr[n+2];

    string line,num;
    
    getline(cin,line);
    int s = line.size();

    for(int i = 0 ; i < s; i++)
    {
        if(line[i] == ' '){
            int check = stoi(num);
            if(check > n || check < 1 || j >= n)
            {
                cout << "`Out of range`";
                return 0;
            }
            arr[check] = check;
            j++;
            num.clear();
        }
        else{
            num += line[i];
            if((i == s-1))
            {
                int check = stoi(num);
                if(check > n || check < 1 || j >= n)
                {
                    cout << "`Out of range`";
                    return 0;
                }
                arr[check] = check;
                j++;
                num.clear();
            }
        }
    }
    for(int k = 1 ; k <= n ; k++)
    {
        if(arr[k] != k)
        {
            cout << k;
            return 0;
        }
    }
    printf("");
    return 0;
}
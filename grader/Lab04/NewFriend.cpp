#include <iostream>

using namespace std;

int main()
{
    int n;
    string l;
    getline(cin,l);
    n = stoi(l);
    int arr[n+1], j = 0;
    string line,num;
    getline(cin,line);
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = 0;
    }
    for(int i = 0 ; i < line.size(); i++)
    {
        if(line[i] == ' '){
            int check = stoi(num);
            if(check > n || j > n)
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
            if((i == line.size()-1))
            {
                int check = stoi(num);
                if(check > n || j > n)
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
    for(int i = 1 ; i <= n ; i++)
    {
        // cout << arr[i] << " ";
        if(arr[i] == 0)
        {
            cout << i;
        }
    }
}
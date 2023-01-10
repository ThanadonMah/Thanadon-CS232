#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    int arr[20], j = 0, max = 0;
    string line,num;

    getline(cin,line);
    int s = line.size();

    for(int i = 0 ; i < s; i++)
    {
        if(line[i] == ' '){
            int check = stoi(num);
            arr[j] = check;
            if(check > max)
            {
                max = check;
            }
            j++;
            num.clear();
        }
        else{
            num += line[i];
            if((i == s-1))
            {
                int check = stoi(num);
                arr[j] = check;
                if(check > max)
                {
                    max = check;
                }
                j++;
                num.clear();
            }
        }
    }

    float k = j;
    int balance = 1;
    int chk[max+2];

    for(int i = 0 ; i < max+2 ; i++)
    {
        chk[i] = 0;
    }
    for(int i = 0 ; i < j ; i++)
    {
        chk[arr[i]]++;
    }
    for(int i = 0 ; i <= max ; i++)
    {
        if(chk[i] > k/2)
        {
            cout << i << " ";
            balance = 0;
        }
    }
    if(balance == 1)
    {
        cout << "Balance (T-T)";
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> getArray(string input) {
    vector<int> array;
    string num;
    int n = input.size();
    for (int i = 0; i < n; i++) {
        if (input[i] == ' ') 
        {
            int temp = stoi(num);
            array.push_back(temp);
            num.clear();
        } 
        else 
        {
            num += input[i];
        }
        if (i == n-1) 
        {
            int temp = stoi(num);
            array.push_back(temp);
        }
    }
    return array;
}
bool checkPositive(vector<int> array) 
{
    int size = array.size();
    for (int i = 0; i < size; i++) 
    {
        if (array.at(i) <= 0)
        {
            return false;
        }
    }
    return true;
}
vector<int> sortFunction(vector<int> array) 
{
    bool check = false;
    vector<int> temp;
    while (!check) {
        int size = array.size();
        for (int i = 0; i < size; i++) {
            if (i < size-1) {
                if (array.at(i) < array.at(i+1)) 
                {
                    temp.push_back(array.at(i+1));
                    temp.push_back(array.at(i));
                    i++;
                } 
                else 
                {
                    temp.push_back(array.at(i));
                }
            } 
            else 
            {
                temp.push_back(array.at(i));
            }
        }
        array.clear();
        array = temp;
        temp.clear();

        check = true;
        for (int i = 0; i < size-1; i++) 
        {
            if (array.at(i) < array.at(i+1))
            {
                check = false;
            }
        }
    }
    return array;
}
int countCoins(int coins, int n) 
{
    int count = 0;
    while (n >= coins) {
        n = n - coins;
        count ++;
    }
    cout << coins << ": " << count << "\n";
    return n;
}
int main() 
{
    string input;
    cout << "Coins: ";
    getline(cin, input);
    vector<int> array = getArray(input);
    if (array.size() == 0) 
    {
        return 0;
    } 
    else 
    {
        if (!checkPositive(array)) 
        {
            cout << "Just because a thing can be done, does not mean that it should be done.";
        } 
        else 
        {
            int n;
            cout << "Cash: ";
            cin >> n;
            array = sortFunction(array);
            int size = array.size();
            for (int i = 0; i < size; i++) 
            {
                if (i == 0) 
                {
                    n = countCoins(array.at(i), n);
                } 
                else 
                {
                    if (array.at(i-1) != array.at(i))
                        n = countCoins(array.at(i), n);
                }
            }
            if (n != 0)
            {
                cout << "Change: " << n;
            }
        }
    }
}
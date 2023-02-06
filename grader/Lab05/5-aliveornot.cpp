# include <iostream>
# include <vector>
using namespace std;
vector<int> getArray(string input) {
    vector<int> array;
    string num;
    int n = input.size();
    for (int i = 0; i < n; i++) {
        if (input[i] == ' ') {
            int temp = stoi(num);
            array.push_back(temp);
            num.clear();
        } else if (input[i] == '.') {
            array.push_back(-1);
        } else {
            num += input[i];
        }
        if (i == n-1) {
            int temp = stoi(num);
            array.push_back(temp);
        }
    }
    return array;
}
bool checkPositive(vector<int> array) {
    int size = array.size();
    for (int i = 0; i < size; i++) {
        if (array.at(i) <= 0)
            return false;
        if (i != 0)
            if (array.at(i-1) == array.at(i))
                return false;
    }
    return true;
}
vector<int> sortFunction(vector<int> array) {
    bool check = false;
    vector<int> temp;
    while (!check) {
        int size = array.size();
        for (int i = 0; i < size; i++) {
            if (i < size-1) {
                if (array.at(i) < array.at(i+1)) {
                    temp.push_back(array.at(i+1));
                    temp.push_back(array.at(i));
                    i++;
                } else {
                    temp.push_back(array.at(i));
                }
            } else {
                temp.push_back(array.at(i));
            }
        }
        array.clear();
        array = temp;
        temp.clear();

        check = true;
        for (int i = 0; i < size-1; i++) {
            if (array.at(i) < array.at(i+1))
                check = false;
        }
    }
    return array;
}
int countCoins(int coins, int n) {
    int count = n / coins;
    n = n - (coins * count);
    cout << coins << ": " << count << "\n";
    return n;
}
int main() {
    // get coin
    string input;
    // cout << "Coins: ";
    getline(cin, input);
    if (input == "") {
        return 0;
    } else {
        vector<int> array = getArray(input);
        int size = array.size();
        if (!checkPositive(array)) {
            cout << "Just because a thing can be done, does not mean that it should be done.";
        } else {
            // get n
            float n;
            // cout << "Cash: ";
            string input2;
            getline(cin, input2);
            if (input2 == "") {
                return 0;
            } else {
                n = stof(input2);
                if (n < 0 || n - (int) n != 0) {
                    return 0;
                } else {
                    array = sortFunction(array);

                    for (int i = 0; i < size; i++) {
                        n = countCoins(array.at(i), n);
                    }
                    if (n != 0)
                        cout << "Change: " << n;
                }
            }
        }
    }
}
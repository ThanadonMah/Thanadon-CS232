#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string n,m;
    // get Value
    getline(cin,n);
    getline(cin,m);

    vector<int> array,array2;
    string num;
    // get number from n
    for(int i = 0;i<n.size();i++){
        if(n[i] == ' '){
           int check = stoi(num);
            array.push_back(check);
            num.clear();
        }
        else{
            num += n[i];
            if((i == n.size()-1))
            {
                int check = stoi(num);
                array.push_back(check);
                num.clear();
            }
        }
    }
    //get number from m
    for(int i = 0;i< m.size();i++){
        if(m[i] == ' '){
            int check = stoi(num);
            array2.push_back(check);
            num.clear();
        }
        else{
            num += m[i];
            if((i == m.size()-1))
            {
                int check = stoi(num);
                array2.push_back(check);
                num.clear();
            }
        }
    }
    // bool Chk[n.size()];
    // for(int i = 0 ;i<n.size();i++){
    //     Chk[i] = true;
    // }
    for(auto i = array.begin(); i != array.end();++i){
        for(auto j = array2.begin();j != array2.end();j++){
            if(*i == *j){
                cout << *i << ' ';
                array2.erase(j);
                // Chk[*j]=false;
                break;
            }
        }
    }
    
}
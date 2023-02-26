#include<vector>
#include<map>
#include<string>
#include<iostream>

using namespace std;

map<char, int> frequent;
map<char, bool> check;
map<char, string> output;
vector<pair<int, string> > v;
string line, unique="";

void toUpper()
{
    for(int i=0 ; i<line.length() ; i++) {
        char c = toupper(line[i]);
        frequent[c]++;
        if(check[c] == false){
            check[c] = true;
            unique = unique + c;
        }
    }
}

void count()
{
    for(int i=0;i<unique.length();i++) {
        string temp = "";
        temp = temp + unique[i];
        vector<pair<int,string> >::iterator itr = v.begin();
        while(itr!=v.end() && frequent[unique[i]] >= itr->first) itr++;
        v.insert(itr,make_pair(frequent[unique[i]],temp));
    }
}

void encode()
{
    while(v.size() > 1)
    {
        vector<pair<int,string> >::iterator left=v.begin(), right=v.begin()+1;
        for(int i=0;i<left->second.length();i++) 
        {
            output[left->second[i]] = "0" + output[left->second[i]];
        }
        for(int i=0;i<right->second.length();i++) 
        {
            output[right->second[i]] = "1" + output[right->second[i]];
        }
        pair<int,string> p = make_pair(left->first+right->first,left->second+right->second);
        v.erase(left,right+1);

        vector<pair<int,string> >::iterator itr=v.begin();
        while(itr!=v.end() && p.first > itr->first) itr++;
        v.insert(itr,p);
    }
}

void displayCode()
{
    for(int i=0 ; i<line.length() ; i++) 
    {
        cout << output[toupper(line[i])];
    }
}

int main()
{
    getline(cin, line);
    toUpper();
    count();
    encode();
    displayCode();
}
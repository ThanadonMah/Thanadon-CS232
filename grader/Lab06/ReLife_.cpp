#include<vector>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    map<char, int> fre;
    map<char, bool> check;
    map<char, string> code;
    vector<pair<int, string> > v;
    string line, unique="";
    getline(cin, line);

    for(int i=0; i<line.length(); i++) {
        char c = toupper(line[i]);
        fre[c]++;
        if(check[c] == false){
            check[c] = true;
            unique = unique + c;
        }
    }

    for(int i=0;i<unique.length();i++) {
        string temp = "";
        temp = temp + unique[i];
        vector<pair<int,string> >::iterator itr = v.begin();
        while(itr!=v.end() && fre[unique[i]] >= itr->first) itr++;
        v.insert(itr,make_pair(fre[unique[i]],temp));
    }

    while(v.size()>1)
    {
        vector<pair<int,string> >::iterator l=v.begin(), r=v.begin()+1;
        for(int i=0;i<l->second.length();i++) code[l->second[i]] = "0" + code[l->second[i]];
        for(int i=0;i<r->second.length();i++) code[r->second[i]] = "1" + code[r->second[i]];
        pair<int,string> p = make_pair(l->first+r->first,l->second+r->second);
        v.erase(l,r+1);

        vector<pair<int,string> >::iterator itr=v.begin();
        while(itr!=v.end() && p.first > itr->first) itr++;
        v.insert(itr,p);
    }

    for(int i=0;i<line.length();i++) cout << code[toupper(line[i])];
}
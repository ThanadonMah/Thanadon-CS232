#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> array){
    for(auto i = array.begin();i != array.begin();i++){
        cout << *i;
    }
}
void selectionSort(vector<int> array){
    for(int i=0;i<array.size()-2;i++){
        for(int j=i+1;j<array.size()-1;j++){
            if(array[i] > array[j]){
                swap(array[i],array[j]);
            }
        }
    }
    print(array);
}

int main(){
    vector<int> array;
    array = {5,9,41,56,23,64,29,65,1};
    for(auto i = array.begin();i != array.begin();i++){
        cout << *i;
    }
    selectionSort(array);
}
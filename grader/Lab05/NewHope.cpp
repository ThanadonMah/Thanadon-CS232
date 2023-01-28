#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > matrix) {
	for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void multiply(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C) {
	int N = 4;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main() {

    string line,num;
    int j = 0, k = 0;
    getline(cin,line);
    vector<vector<int>> A(4, vector<int>(4));

    for(int i = 0 ; i < line.size(); i++)
    {
        if(line[i] == ' '){
            int check = stoi(num);
            A[j][k] = check;
            k++;
            if(k == 4)
            {
                k = 0;
                j++;
            }
            num.clear();
        }
        else{
            num += line[i];
            if((i == line.size()-1))
            {
                int check = stoi(num);
                A[j][k] = check;
                k++;
                if(k == 4)
                {
                    k = 0;
                    j++;
                }
                num.clear();
            }
        }
    }

    
    j = 0, k = 0;
    getline(cin,line);
    vector<vector<int>> B(4, vector<int>(4));

    for(int i = 0 ; i < line.size(); i++)
    {
        if(line[i] == ' '){
            int check = stoi(num);
            B[j][k] = check;
            k++;
            if(k == 4)
            {
                k = 0;
                j++;
            }
            num.clear();
        }
        else{
            num += line[i];
            if((i == line.size()-1))
            {
                int check = stoi(num);
                B[j][k] = check;
                k++;
                if(k == 4)
                {
                    k = 0;
                    j++;
                }
                num.clear();
            }
        }
    }

	vector<vector<int>> C(4, vector<int>(4));
    
	multiply(A, B, C);

	print(C);
	return 0;
}
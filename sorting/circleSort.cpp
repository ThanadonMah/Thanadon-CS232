# include<iostream>
using namespace std;
int fiboTopDown(int n) {
    int array[n+1];
    array[0] = 0;
    array[1] = 1;
    for (int i = 2; i <= n; i++) {
        array[i] = array[i-1] + array[i-2];
    }
    return array[n];
}
int main() {
    int n;
    cin >> n;
    cout << fiboTopDown(n);
}
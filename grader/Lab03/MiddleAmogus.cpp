#include <iostream>

using namespace std;

void swap(float* a, float* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  

int partition(float arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i
        = (low
           - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
void quickSort(float arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  

int main()
{
    int first,second;
    cin >> first >> second;
    float arr[first+second];
    for(int i = 0 ; i < first+second ; i++)
    {
        cin >> arr[i]; 
    }

    quickSort(arr,0,first+second-1);
    if(first+second == 0)
    {
        return 0;
    }
    if((first+second) % 2 == 0)
    {
        cout << (arr[(first+second) / 2 - 1] + arr[(first+second) / 2] ) / 2;
    }
    else
    {
        cout << arr[(first+second) / 2];
    }
}
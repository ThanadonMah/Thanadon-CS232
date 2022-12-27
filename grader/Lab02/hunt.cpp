#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i
        = (low
           - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[100], j = 0, value;
    string line,num;
    getline(cin,line);
    for(int i = 0 ; i < line.size(); i++)
    {
        if(line[i] == ' '){
            int check = stoi(num);
            arr[j] = check;
            j++;
            num.clear();
        }
        else{
            num += line[i];
            if((i == line.size()-1))
            {
                int check = stoi(num);
                arr[j] = check;
                j++;
                num.clear();
            }
        }
    }


    quickSort(arr, 0, j-1);
    printArray(arr, j);
    return 0;
}
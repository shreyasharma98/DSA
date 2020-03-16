#include<iostream>
using namespace std;
void swapAlternate(int arr[],int size){

    int temp;
    for(int i=0;i<size-1;i++)
    {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        i++;
    }
}


int main()
{
  int size;
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++)
    {
    cin >> arr[i];
    }
  swapAlternate(arr, size);
    for(int i = 0; i < size; i++)
    {
    cout << arr[i] << " ";
    }
  delete arr;
}

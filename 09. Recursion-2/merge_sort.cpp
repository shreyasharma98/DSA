#include <iostream>
using namespace std;

void merge(int input[],int start,int end,int mid)
{
    int i = start;
    int j = mid+1;
    int n = end-start;
    int arr[n];
    int k = 0;
    while(i <= mid && j<=end)
    {
        if(input[i]<input[j])
        {
            arr[k] = input[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = input[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        arr[k] = input[i];
        i++;
        k++;
    }
    while(j <= end)
    {
        arr[k] = input[j];
            j++;
            k++;
    }
        int m = 0;
    for(int i = start;i<=end;i++)
    {
        input[i] = arr[m++];
    }

}
void merge_sort(int input[],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int mid = (start+end)/2;
    merge_sort(input,start,mid);
    merge_sort(input,mid+1,end);
    merge(input,start,end,mid);
}
void mergeSort(int input[], int size){
	if(size == 0 || size==1)
    {
        return;
    }
    merge_sort(input,0,size-1);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}


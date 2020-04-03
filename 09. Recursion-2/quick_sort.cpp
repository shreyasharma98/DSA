#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partitioning(int input[],int start, int end)
{
    int ctr = 0;
    for(int i = start+1;i<=end;i++)
    {
        if(input[i]<input[start])
        {
            ctr++;
        }
    }
    swap(&input[start],&input[start+ctr]);
    int x = input[start+ctr],idx = start+ctr;
    int i = start , j = end;
    while(i<=j)
    {
        if(input[i] <= x)
        {
            i++;
        }
        else if(input[j] > x)
        {
            j--;
        }
        else
        {
            swap(&input[i],&input[j]);
            i++;j--;
        }
    }
    return j;
}
void quick_sort(int arr[],int start,int end)
{
    int c;
    if(start>=end)
    {
        return;
    }
    c = partitioning(arr,start,end);
    quick_sort(arr,start,c);
    quick_sort(arr,c+2,end);

}
void quickSort(int input[], int size) {
  if(size == 0 || size == 1)
  {
      return;
  }
    quick_sort(input,0,size-1);


}
int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
 quickSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}


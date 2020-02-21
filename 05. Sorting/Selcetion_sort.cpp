
#include <iostream>
using namespace std;
void Selection_sort(int *arr, int n){
    for(int i = 0;i<n-1;i++)
    {
        int min = arr[i],min_idx = i;
        for(int j =i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_idx] = temp;
    }

}

int main() {

	int size,val;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];
	Selection_sort(input,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;
}




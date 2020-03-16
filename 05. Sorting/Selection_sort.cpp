
#include <iostream>
using namespace std;

void SelctionSort(int arr[], int n){

    for(int i =0;i<n-1;i++)
    {
        int k = i+1 , min = arr[i+1];
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                k = j;
            }
        }
        int  temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }


}


int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	SelctionSort(input,size);

	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;
}


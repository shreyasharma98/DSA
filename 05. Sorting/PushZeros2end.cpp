

#include <iostream>
using namespace std;

void PushZeros(int arr[], int n){
    int k = 0;
    for(int i =0;i<n;i++)
    {
        if(arr[i] != 0)
        {
            arr[k] = arr[i];
            k++;
        }
    }
    while(k<n)
    {
        arr[k] = 0;
        k++;

    }


}


int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	PushZeros(input,size);

	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;
}


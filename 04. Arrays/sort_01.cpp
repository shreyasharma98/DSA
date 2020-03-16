#include <iostream>
#include <algorithm>
using namespace std;

void SortZeroesAndOne(int arr[], int n){

    int ctr = 0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]==1)
        {
            arr[i] = 0;
            ctr++;
        }
    }
    for(int i =n-ctr;i<n;i++)
    {
        arr[i] = 1;
    }


}


int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	SortZeroesAndOne(input,size);

	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;
}


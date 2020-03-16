
#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i =1;i<n;i++)
    {
        int val = arr[i];
        for(int k = i-1;k>=0;k--)
        {
            if(val <arr[k])
            {
                arr[k+1] = arr[k];
                arr[k] = val;
            }
        }
    }
}



int main(){

	int size;
	cin>>size;

	int * input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	insertion_sort(input,size);

	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";

}

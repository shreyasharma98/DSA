#include<iostream>
using namespace std;
int FindUnique(int arr[],int n)
{
    int unique=0;
    for(int i=0;i<n;i++)
    {
        unique ^= arr[i];
    }
    return unique;
}
int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	cout<<FindUnique(input,size)<<endl;

	return 0;
}


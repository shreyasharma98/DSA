#include<algorithm>
#include <iostream>
using namespace std;
void tripletSum(int arr[],int n,int x)
{
    sort(arr,arr+n);
    for(int i =0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)

        {
            for(int k = j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k] == x)
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;

            }
        }
    }
}
int main() {

	int size;
	int x;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;
	tripletSum(input,size,x);

	return 0;
}


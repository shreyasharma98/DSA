#include <iostream>
using namespace std;
void pairSum(int arr[],int n,int x)
{
    for(int i =0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)

        {
            if(arr[i]+arr[j] == x)
            {
                if(arr[i]<arr[j])
                cout<<arr[i]<<" "<<arr[j]<<endl;
                else
                cout<<arr[j]<<" "<<arr[i]<<endl;
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
	pairSum(input,size,x);

	return 0;
}


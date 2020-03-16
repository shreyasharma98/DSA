#include<iostream>
using namespace std;

int FindDuplicates(int * arr, int n){
    for(int i =0;i<n;i++)
    {
        for(int j = 0 ;j<n;j++)
        {
            if(i!=j)
            {
                if(arr[i] == arr[j])
                {
                    return arr[i];
                }
            }
        }
    }
}

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	cout<<FindDuplicates(input,size)<<endl;

	return 0;
}



#include <iostream>
using namespace std;

int FindSortedArrayRotation(int arr[], int n) {
int l = 0,r=n-1;
    while(l<r)
    {
        int m=l+(r-l)/2;
        if(arr[m] > arr[r])
        {
            l = m+1;
        }
        else
        {
            r = m;
        }
    }
    return l;
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	cout<<FindSortedArrayRotation(input,size);

	return 0;

}


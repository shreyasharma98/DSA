
#include <iostream>
using namespace std;

void sort012(int arr[], int n)  {
    int j = 0, k=n-1;
    for(int i =0;i<k;i++)
        {
            if(arr[i] == 0)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                j++;
            }
           if(arr[i] == 2)
            {
                int temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
                k--;i--;
            }
        }
}
int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];
    sort012(input,size);

	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;
}


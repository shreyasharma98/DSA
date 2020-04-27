
#include <iostream>
using namespace std;
void reverse(int arr[],int start ,int end)
{
    while(start<=end)
    {
        int temp;
        temp = arr[start];
        arr[start]=arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void Rotate(int arr[], int d, int size) {
    reverse(arr,0,size-1);
    reverse(arr,size-d,size-1);
    reverse(arr,0,size-d-1);
}

int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;

    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}

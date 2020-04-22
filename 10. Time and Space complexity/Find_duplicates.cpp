#include <iostream>
using namespace std;

int MissingNumber(int arr[],int n)
{

    int ideal_sum = ((n-1)*(n-2))/2;
    int extra=0;
    for(int i = 0;i<n;i++)
    {
        extra+=arr[i];
    }
    return extra-ideal_sum;
}
int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	cout << MissingNumber(input, size);

	delete [] input;

	return 0;
}

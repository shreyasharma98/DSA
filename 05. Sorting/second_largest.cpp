#include <iostream>
using namespace std;

int Second_largest(int arr[], int n){
    int f_large = arr[0],s_large = INT_MIN;
    for(int i = 1;i<n;i++)
    {
        if(arr[i] > f_large)
        {
            s_large = f_large;
            f_large = arr[i];
        }
        else if(f_large > arr[i] && s_large < arr[i])
        {
            s_large = arr[i];
        }
    }

    return s_large;


}
int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	cout<<Second_largest(input,size);


	return 0;
}


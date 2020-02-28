#include <iostream>
using namespace std;
void Rotate(int a[], int d, int n) {
        int k = 0;
        while(d--)
        {
            int temp = a[0];
            for(int  i = 0;i<n-1;i++)
            {
                a[i] = a[i+1];
                a[i+1]  = temp;
            }
        }
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


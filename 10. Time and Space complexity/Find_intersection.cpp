#include <iostream>
#include<algorithm>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
    int i = 0,j=0;
    sort(input1,input1+size1);
    sort(input2,input2+size2);
    while(i<size1 && j<size2)
    {
        if(input1[i] == input2[j])
        {
            cout<<input1[i]<<endl;
            i++;
            j++;
        }
        else if(input1[i] < input2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}


int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];

	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];

	for(int i=0;i<size2;i++)
		cin>>input2[i];


	intersection(input1,input2,size1,size2);


	return 0;
}

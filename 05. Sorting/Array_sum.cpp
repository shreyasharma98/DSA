
#include <iostream>
using namespace std;


void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[]){
int carry = 0, i= size1,j = size2;
 for(int k = 1+std::max(size1,size2); k>=0;k--)
{
    int ans = 0;
    if(i<0 && j < 0)
        ans = carry;
    else if(i<0)
        ans = carry + input2[j];
    else if(j<0)
        ans = carry + input1[i];
    else
        ans = carry + input1[i] + input2[j];

    if(ans > 0)
    {
        int rem = ans %10;
        carry = ans/10;
        ans = rem;
    }
    i--;j--;
    output[k]= ans ;
}
}

int main(){
	int size1,size2;
	cin>>size1;
	int * input1=new int[1+size1];

	for(int i=0;i<size1;i++)
		cin>>input1[i];

   	 cin>>size2;
	 int * input2=new int[1+size2];

	for(int i=0;i<size2;i++)
		cin>>input2[i];

	int *output=new int[1+max(size1,size2)];
	int outsize = 1+max(size1,size2);
	sumOfTwoArrays(input1,size1,input2,size2,output);

	for(int i=0;i<outsize;i++)
		cout<<output[i]<<" ";


}


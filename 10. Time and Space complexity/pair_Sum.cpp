#include<algorithm>
#include <iostream>
using namespace std;
int ctr(int arr[],int idx,int n)
{
    int c = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == arr[idx])
        {
            c++;
        }
    }
    return c;
}
void pairSum(int input[], int size, int x) {
    sort(input,input+size);
    int i = 0,j=size-1;
    while(i<j)
    {
        if(input[i]+input[j] == x)
        {
            if(input[i] == input[j])
            {
                for(int k = 0;k<j-i;k++)
                    cout<<input[i]<<" "<<input[j]<<endl;

                i++;
            }
            else{
            int ctr_i = ctr(input,i,size);
            int ctr_j = ctr(input,j,size);
            for(int k = 0;k<ctr_i*ctr_j;k++)
                    cout<<input[i]<<" "<<input[j]<<endl;

            i+=ctr_i;
            j-=ctr_j;
            }
        }
        else if(input[i]+input[j] > x)
        {
            j--;
        }
        else
        {
            i++;
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

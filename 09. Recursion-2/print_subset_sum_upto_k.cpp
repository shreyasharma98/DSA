#include <iostream>
using namespace std;
void printSubsetSumToK_helper(int input[], int size, int k,int output[],int m)
{

    if(size == 0)
    {
        if(k == 0)
        {
            for(int i = 0;i<m;i++)
            {
                cout<<output[i]<<" ";
            }
        cout<<endl;
        return;
        }
        else
            {
            return;
            }
    }
    int newOutput[1000];
    int i =0;
    for(;i<m;i++)
    {
        newOutput[i+1]= output[i] ;
    }
    newOutput[0] = input[0];
    printSubsetSumToK_helper(input+1,size-1,k-input[0],newOutput,m+1);
    printSubsetSumToK_helper(input+1,size-1,k,output,m);
}
void printSubsetSumToK(int input[], int size, int k) {
    int output[100];
    printSubsetSumToK_helper(input,size,k,output,0);
}

int main() {
  int input[100],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}

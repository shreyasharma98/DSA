#include <iostream>
using namespace std;
void subset_helperss(int input[],int n,int output[],int m)
{
    int newOutput[1000];
    if(n == 0)
    {
        for(int i = 0;i<m;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int i =0;
    for(;i<m;i++)
    {
        newOutput[i]= output[i] ;
    }
    newOutput[i] = input[0];
    subset_helperss(input+1,n-1,output,m);
    subset_helperss(input+1,n-1,newOutput,m+1);
}
void printSubsetsOfArray(int input[], int size) {
   int output[1000];
   subset_helperss(input,size,output,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}


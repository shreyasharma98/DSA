
#include <iostream>
using namespace std;
#include<algorithm>
void pairSum(int input[], int size, int x) {
    sort(input,input+size);
    int left = 0,right = size -1;
    while(left<right)
    {
        if(input[left]+input[right] < x)
            left++;
        else if(input[left]+input[right] > x)
            right--;
        else
        {
            int tempLeft = input[left];
            int leftCtr = 0;
            while(tempLeft == input[left])
            {
                leftCtr++;left++;
            }
            int tempRight = input[right];
            int printCtr;
            if(tempLeft == tempRight)
            {
                printCtr = (leftCtr*(leftCtr-1))/2;
            }
            else
            {
                int rightCtr = 0;
                while(tempRight == input[right])
                {
                    rightCtr++;right--;
                }
                printCtr = leftCtr*rightCtr;
            }
            for(int i = 0;i<printCtr;i++)
                cout<<tempLeft<<" "<<tempRight<<endl;
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

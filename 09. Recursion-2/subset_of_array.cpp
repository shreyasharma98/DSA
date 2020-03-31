#include <iostream>
using namespace std;
int subset_helper(int input[],int n,int output[][20],int i)
{
    if(n == 0)
    {
        output[i][0] = 0;
        return 1;
    }
    int ans = subset_helper(input+1,n-1,output,i++);
    output[i][0] = ans;
    for(int j=1;j<=ans;j++)
    {
        output[i][j] = input[0];
    }
    return ans*2;
}
int subset(int input[], int n, int output[][20]) {
    return subset_helper(input,n,output,0);
}

int main() {
  int input[20],length, output[30][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


#include<iostream>
using namespace std;

int allIndexes(int input[], int n, int x, int output[]) {
    if(n == 0)
    {
        return 0;
    }
    int ans = allIndexes(input+1,n-1,x,output);
    if(input[0] == x)
    {
        for(int i = ans-1;i>=0;i--)
        {
            output[i+1] = output[i]+1;
        }
        output[0] = 0;
        ans++;
    }
    else
    {
        for(int i = ans-1;i>=0;i--)
        {
            output[i] = output[i]+1;
        }
    }
    return ans;
}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;

    delete [] output;


}


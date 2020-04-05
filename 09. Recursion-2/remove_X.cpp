#include<cstring>
#include<iostream>
using namespace std;
void shift(char arr[] , int n)
{
    for(int i = 1;i<=n;i++)
    {
        arr[i-1] = arr[i];
    }
}
void removeX(char input[]) {
    if(strlen(input) == 0)
    {
        return;
    }
    removeX(input+1);
    if(input[0] == 'x')
    {
        shift(input,strlen(input));
    }
}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

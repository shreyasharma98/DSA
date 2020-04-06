#include <iostream>
#include<cstring>
using namespace std;
int func(char input[],int n)
{
    if(n == 0)
    {
        return 0;
    }
    int res = func(input,n-1);
    int x = input[n-1] -48;
    return (res*10) +x;
}

int stringToNumber(char input[]) {
    return func(input,strlen(input));
}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;

}

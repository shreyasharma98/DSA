#include <iostream>
using namespace std;
int staircase(int n){
    if(n == 0)
    {
        return 0;
    }
    if(n==1)
    {

        return 1;
    }
    if(n==2)
    {
        return 1+staircase(n-1);
    }
    if(n == 3)
    {
        return 1+staircase(n-1)+staircase(n-2);

    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}

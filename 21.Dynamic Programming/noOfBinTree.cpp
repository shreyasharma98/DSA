#include<iostream>
#include<cmath>
using namespace std;

int balancedBTs(int h)
{
    int *arr = new int[h+1];
    int mode=(int)pow(10,9) +7;
    for(int i = 0;i<=h;i++)
    {
        arr[i] = 0;
    }
    arr[0] = arr[1] = 1;
    for(int i = 2;i<=h;i++)
    {
        int x = arr[i-1];
        int y = arr[i-2];
        int temp1 =(int)(((long)(x)*x) % mode);
        int temp2= (int)((2*(long)(x)*y ) % mode);
        int ans = (temp1+temp2)%mode;
        arr[i] = ans;
    }

    return arr[h];
}
/*
int balancedBTs(int h)
{
   if (h == 0 || h == 1)
        return 1;
    int mode=(int)pow(10,9) +7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    int temp1 =(int)(((long)(x)*x) % mode);
    int temp2= (int)((2*(long)(x)*y ) % mode);
    int ans = (temp1+temp2)%mode;
    return ans;
}
*/
int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}

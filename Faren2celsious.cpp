
#include<iostream>
using namespace std;
void printTable(int start, int end, int step) {
    for(int i = start;i<=end;i+=step)
    {
        cout<<i<<" "<<(i-32)*5/9<<endl;
    }
}
int main()
{
    printTable(0,100,20);
}


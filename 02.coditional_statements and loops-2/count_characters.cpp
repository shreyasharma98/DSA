#include<iostream>
using namespace std;

int main()
{
    int spaces=0,digits=0,characters=0;
    char s = cin.get();
    while(s!='$')
    {
        if(s>='a'&&s<='z')
        {
            characters++;
        }
        if(s>='0'&& s<='9')
        {
            digits++;
        }
        if(s==' '||s=='\t'||s=='\n')
        {
            spaces++;
        }
        s = cin.get();

    }
    cout<< characters <<" "<< digits<<" "<<spaces;
    return 0;
}

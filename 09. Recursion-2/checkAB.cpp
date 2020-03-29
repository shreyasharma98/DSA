#include<iostream>
#include<cstring>
using namespace std;
bool checkAB(char input[])
{
    if(input[0] == '\0')
    {
        return true;
    }
    if(input[0] == 'a')
    {
        return checkAB(input+1);
    }
    if(input[0] == 'b')
    {
        if(input[1] == 'b')
        {
            return checkAB(input+2);
        }
        else
        {return false;
    }}

}
int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}

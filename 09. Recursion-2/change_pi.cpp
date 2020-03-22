#include<cstring>
#include<iostream>
using namespace std;
void shift(char input[] , int start ,int n)
{
    for(int i = n ; i>=start ;i--)
    {
        input[i+2] = input[i];
    }

}
void replacePi(char input[]) {
	if(strlen(input) ==0 || strlen(input) ==1)
    {
        return;
    }
    replacePi(input+1);
    if(input[0] == 'p' && input[1] == 'i')
    {
        shift(input, 2,strlen(input));
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
    input[strlen(input)+2] = '\0';
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout<<input;
}

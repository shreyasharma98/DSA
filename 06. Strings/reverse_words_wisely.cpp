#include<iostream>
#include<cstring>
using namespace std;
void reverse_word(char str[])
{
    int start = 0 , end = strlen(str) -1;
    while(start <= end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void re_reverse(char str[] , int start , int end)
{
    while(start <= end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void reverseStringWordWise(char input[]) {
    reverse_word(input);
    int start = 0;
   for(int i=0;i<=strlen(input);i++)
    {
        if(input[i] == ' '|| input[i] == '\0')
        {
            int end = i-1;
            re_reverse(input,start,end);
            start = i+1;
        }

    }

}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout<<input;
}

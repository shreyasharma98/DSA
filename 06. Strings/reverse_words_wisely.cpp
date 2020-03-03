// input - given string
// You need to update in the given string itself. No need to print or return anything
#include<cstring>
void reverseStringWordWise(char input[]) {
   int start=0,end=strlen(input)-1;
    while(start<=end)
    {
        char temp;
        temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
    start = 0;
    for(int i=0;i<=strlen(input);i++)
    {
        if(input[i] == ' ' || input[i] == '\0')
        {
            end = i-1;
            while(start<=end)
            {
                char temp;
                temp = input[start];
                input[start] = input[end];
                input[end] = temp;
                start++;
                end--;
            }
            start = i+1;
        }

    }

}

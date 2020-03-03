#include <cstring>
bool checkPalindrome(char str[]){
    
    int start = 0,end = strlen(str)-1;
    while(start<=end)
    {
        if(str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

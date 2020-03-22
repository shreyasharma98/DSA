#include <iostream>
#include<cstring>
using namespace std;
bool check(char input[],int start,int end )
{
    if(end-start == 0 ||end-start == 1)
    {
        return true;
    }
    if(input[start] != input[end])
    {
        return false;
    }
    else{
        return check(input,start+1,end-1);
    }

}
bool checkPalindrome(char input[]) {
   int start = 0;
   int end = strlen(input)-1;
    bool ans = check(input,start,end);
    return ans;
}

int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

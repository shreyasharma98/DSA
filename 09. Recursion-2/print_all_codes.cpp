#include <iostream>
#include <string>
using namespace std;
int find_number(char ch1,char ch2)
{
    int dig1 = ch1-'0';
    int dig2 = ch2-'0';
    int n = dig1*10 + dig2;

    return n;
}
void printAllPossibleCodes_helper(string input,string output)
{
    if(input.size() == 0)
    {
        cout<<output<<endl;
        return;
    }
    if(input.size() == 1)
    {
        int dig1 = input[0]-'0';
        char ch1 = 'a'+dig1-1;
        cout<<output+ch1<<endl;
        return;
    }
    int dig1 = input[0] - '0';
    char ch = dig1+'a'-1;
    printAllPossibleCodes_helper(input.substr(1),output+ch);
    int dig2 = find_number(input[0],input[1]);
    if(dig2>=10 && dig2<=26)
    {
        char ch = dig2+'a'-1;
        printAllPossibleCodes_helper(input.substr(2),output+ch);
    }
}
void printAllPossibleCodes(string input) {
 printAllPossibleCodes_helper(input,"");
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}

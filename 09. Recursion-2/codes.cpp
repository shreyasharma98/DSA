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

int getCodes(string input, string output[1000]) {
    if(input.size() == 0)
    {
        output[0] = ' ';
        return 1;
    }
    if(input.size() == 1)
    {
        int dig1 = input[0]-'0';
        output[0] = 'a'+dig1-1;
        return 1;
    }
   string single_output[1000],double_output[1000];
   int n1 = getCodes(input.substr(1),single_output);
   int n2 = getCodes(input.substr(2),double_output);
   int dig1 = input[0]-'0';
   char ch1 = 'a'+dig1-1;
   int dig2 = find_number(input[0],input[1]);
   char ch2;
   if(dig2>=10&&dig2<=26)
   {
       ch2 = 'a'+dig2-1;
   }
   else{n2 = 0;}
   for(int  i = 0;i<n1;i++)
   {
       output[i] = ch1+single_output[i];
   }
   for(int i = n1;i<=n1+n2;i++)
    {
       output[i] = ch2+double_output[i-n1];
   }
   return n1+n2;

}

int main(){
    string input;
    cin >> input;

    string output[1000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

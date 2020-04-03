#include <iostream>
#include <string>
using namespace std;
string dial_keys(int num)
{
    string input[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return input[num];
}
void key_pad_helper(int num,string output)
{
    if(num == 0)
    {
        cout<<output<<endl;
        return;
    }
    string str = dial_keys(num%10);
    for(int i = 0;i<str.size();i++)
    {
        key_pad_helper(num/10,str[i]+output);
    }
}
void printKeypad(int num){
    string output = "";
    key_pad_helper(num,output);
}



int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

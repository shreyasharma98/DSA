#include<iostream>
#include<string>
using namespace std;
void print_subseq(string input,string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }
    print_subseq(input.substr(1),output);
    print_subseq(input.substr(1),output+input[0]);
}
int main()
{
    string s;
    cin>>s;
    string output ="";
    print_subseq(s,output);
    return 0;
}

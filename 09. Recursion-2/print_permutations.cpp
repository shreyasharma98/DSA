#include <iostream>
#include <string>
using namespace std;
void printPermutations_helper(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return ;
    }

    for(int i = 0;i<input.length();i++)
    {
        printPermutations_helper(input.substr(0,i)+input.substr(i+1),output+input[i]);
    }
}
void printPermutations(string input){

    	printPermutations_helper(input,"");
}
int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}

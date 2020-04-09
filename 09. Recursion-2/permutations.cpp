#include<iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input.length() == 1)
    {
        output[0] = input[0];
        return 1;
    }
    int k = 0;
    for(int i = 0;i<input.length();i++)
    {
        char ch = input[i];
        string ros = input.substr(0,i)+input.substr(i+1);
        string new_output[1000];
        int x = returnPermutations(ros,new_output);
        for(int j=0;j<x;j++)
        {
            output[k++] = ch+new_output[j];
        }
        if(i == input.length()-1)
        {
            return input.length()*x;
        }
    }
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

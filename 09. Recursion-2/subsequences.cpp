#include<iostream>
#include<cmath>
using namespace std;
int sub_sequence(string input, string output[])
{
    if(input.empty())
    {
        output[0]=" ";
        return 1;
    }
    string sub_seq = input.substr(1);
    int size_of_subsequence = sub_sequence(sub_seq,output);
    for(int i = 0;i<size_of_subsequence;i++)
    {
        output[i+size_of_subsequence] = input[0]+ output[i];
    }
    return 2*size_of_subsequence;
}
int main()
{
    string input;
    cin>>input;
    int size = pow(2,input.size());
    string *output= new string[size];
    int ctr = sub_sequence(input,output);
    for(int i = 0;i<ctr;i++)
    {
        cout<<output[i]<<endl;
    }
    delete [] output;
}

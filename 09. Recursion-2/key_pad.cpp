#include <string>
#include<iostream>
using namespace std;
string dial_keys(int num)
{
    string input[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return input[num];
}
void fill_output(string s,string output[],int size)
{
    int x = s.size();
    string temp_array[size];
    int k = 0;
    for(int i=0;i<x;i++)
    {
        for(int j = 0;j<size/x;j++)
        {
            temp_array[k] = output[j]+s[i];
            k++;
        }
    }
    for(int i = 0;i<size;i++)
    {
        output[i] = temp_array[i];
    }

}
int keypad(int num, string output[]){
 if(num == 0)
 {
     output[0] = "";
     return 1;
 }
 int n = num%10;
 int outsize = keypad(num/10,output);
 string str = dial_keys(n);
 int x = outsize*str.size();

 fill_output(str,output,x);
 return x;
 }
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}


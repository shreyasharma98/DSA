#include<cstring>
#include<iostream>
using namespace std;
void stringCompression(char input[]) {
 int j = 0,ctr = 0;
 for(int i = 0;i<strlen(input);i++)
 {
     if(input[i]!=input[i+1])
     {
         input[j++] = input[i];
         int ch = 49+ctr;
        if(ch > 49)
         {
            input[j++] = char(ch);
         }
        ctr = 0;
     }
     else{
        ctr++;
     }
 }
 input[j] = '\0';

  }


int main() {
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}

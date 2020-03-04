#include<iostream>
#include <cstring>
using namespace std;
bool checkPalindrome(char str[]){
    int start = 0 , end = strlen(str) -1;
    while(start <= end)
    {
     if(str[start] != str[end])
     {
         return false;
     }
     start++;
     end--;
    }
}

int main(){

  char str[10000];
  cin.getline(str,10000);

  if(checkPalindrome(str)){
  	cout << "true" << endl;
  }else{
  cout << "false" << endl;
  }
}


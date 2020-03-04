#include<iostream>
using namespace std;


void trimSpaces(char input[]) {
  int j = 0;
  for(int i = 0 ;input[i] !='\0' ;i++)
  {
      if(input[i] != ' ')
      {
          input[j++] = input[i];
      }
  }
  input[j] = '\0';

}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}



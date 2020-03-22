
#include<cstring>
#include <iostream>
using namespace std;

void pairStar(char input[]) {
   if(strlen(input) == 0 || strlen(input) == 1)
   {
       return;
   }
   pairStar(input+1);
   if(input[0] == input[1])
   {
       for(int i =strlen(input); i>=1 ;i--)
       {
           input[i+1]=input[i];
       }
       input[1] = '*';
       input[strlen(input)+1] = '\0';
   }

}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

char* uniqueChar(char *str){
    char* ans = new char[strlen(str)+1];
   unordered_map<char,int> map1;
   for(int i =0 ;i<strlen(str);i++)
   {
       map1[str[i]]++;
   }
   int j = 0;
   for(int i =0 ;i<strlen(str);i++)
   {
       char curr = str[i];
       if(map1[curr] >0)
       {
           ans[j++] = curr;
           map1[curr] = 0;
       }
   }
   ans[j] = '\0';

    return ans;
}
int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}


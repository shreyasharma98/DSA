#include <iostream>
#include<cstring>
#include<climits>
using namespace std;


int find_len(char str[] , int start , int end)
{
    int ctr = 0;
    for(int i = start ; i<= end ;i++ )
    {
        ctr++;
    }
    return ctr;
}
void minLengthWord(char input[], char output[]){
    int a=0,b=0,start = 0,end = 0;
    int min = INT_MAX;
		for(int i = 0 ;i<strlen(input);i++)
        {
            if(input[i] == ' ')
            {
                end = i-1;
                int len = find_len(input,start,end);
                if(len < min)
                {
                    min = len;
                    a = start;
                    b = end;
                }
                start = i+1;
            }

        }
    int i = 0;
    while(a<=b)
    {
        output[i] = input[a];
        i++;
        a++;
    }
    output[i] = '\0';

}
int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}



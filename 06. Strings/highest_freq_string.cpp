#include<cstring>
#include<iostream>
using namespace std;

char highestOccurringChar(char input[]) {

    int freq[256] = {0};
    for(int i = 0;i<strlen(input);i++)
    {
        freq[int(input[i])]+=1;
    }
    int max = freq[0],idx = 0;
    for(int i = 0;i<256;i++)
    {
        if(freq[i] > max)
        {
            max = freq[i];
            idx=i;
        }
    }
    return char(idx);

}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    cout << highestOccurringChar(input) << endl;
}

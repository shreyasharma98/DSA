#include<cstring>
#include<iostream>
using namespace std;

void removeAllOccurrencesOfChar(char input[], char c) {
    int n = strlen(input);
    int j = 0;
    for(int i =0;i<n;i++)
    {
        if(input[i]!=c)
        {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';

}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(input, c);
    cout << input << endl;
}

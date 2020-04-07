#include<iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input)
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

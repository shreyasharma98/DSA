#include <iostream>
#include <string>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    if(numDenominations == 0|| value <= 0)
    {return 0;}
    if()
    int ans = 0;
    if(denominations[0] <= value)
    {
        int a = countWaysToMakeChange(denominations,numDenominations,value-denominations[0]);
        int b = countWaysToMakeChange(denominations+1,numDenominations-1,value);
    ans = a+b;
    }
    int b = countWaysToMakeChange(denominations+1,numDenominations-1,value);
    return ans+b;
}
int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}



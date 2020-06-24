#include<iostream>
#include<iterator>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){

  unordered_map<int,int> map1;
  int maxLen = 0;
  int sum = 0;
	for(int i = 0;i<size;i++)
	{
	    sum+=arr[i];
	   if(map1[sum] > 0)
       {
           int len = i - map1[sum];
           if(len > maxLen)
           {
               maxLen  = len;
           }
       }
       else
       {
           map1[sum] = i;
       }
	}

	return maxLen;

}



int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}


#include<iostream>
#include<iterator>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){

  unordered_map<int,int> map1;
  int maxLen = 0;
  for(int i = 1;i<size;i++)
  {
      arr[i] += arr[i-1];
  }
  int m = 0;
  for(int i = 0;i<size;i++)
  {
      if(arr[i]== 0)
      {
          if(m<i+1)
            m = i+1;
      }
      else if(map1.count(arr[i]) > 0)
      {
          if(m<i - map1[arr[i]])
            m = i - map1[arr[i]];
      }
      else
        map1[arr[i]] = i;
  }

	return m;

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


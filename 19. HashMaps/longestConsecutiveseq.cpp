#include <vector>
#include<iostream>
#include<iterator>
#include<unordered_map>
using namespace std;
int findMinIdx(int a,int b,int *arr,int n)
{
    int p , q;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == a)
            p = i;
        if(arr[i] == b)
            q = i;
    }
    return min(p,q);
}
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	vector<int> v;
	int maxLength = 0;
	int start;
	if(n == 1)
    {
        v.push_back(arr[0]);
        return v;
    }
	unordered_map<int,bool> map1;
	for(int i = 0;i<n;i++)
    {
        map1[arr[i]] = true;
    }
    unordered_map<int,bool>::iterator it = map1.begin();
    while(it!=map1.end())
    {
        int curr = it->first;
        int prev = curr - 1;
        int len = 0;
         while(map1.count(curr) > 0)
            {
                if(map1[curr] == false)
                {
                    break;
                }
                else
                {
                    map1[curr] = false;
                    len++;
                    curr+=1;
                }
            }

            while(map1.count(prev7
3 7 2 1 9 8 17
3 7 2 1 9 8 17) > 0)
            {
                if(map1[prev] == false)
                {
                    break;
                }
                else
                {
                    map1[prev] = false;
                    len++;
                    prev-=1;
                }

            }
            if(len > maxLength)
            {
                maxLength = len;
                start = prev+1;
            }
            if(len == maxLength)
        {
            int newStart = prev+1;
            int firstIs =  findMinIdx(newStart,start,arr,n);
            start = arr[firstIs];
        }
        it++;
        cout<<"start : "<<start<<endl;
    }
    for(int i =0;i<maxLength;i++)
    {
        v.push_back(start++);
    }

    return v;

}


int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);

  for (auto it = ans.begin(); it != ans.end(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}

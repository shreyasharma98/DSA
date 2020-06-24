#include<iostream>
#include<unordered_map>
using namespace std;
int highestFrequency(int *a, int n){
    int max = 0;
    int ele;
	unordered_map<int,int> freqMap;
    for(int i=0;i<n;i++)
    {
        freqMap[a[i]]++;
    }

    for(int i = 0;i<n;i++)
    {
        if(max < freqMap[a[i]])
        {
            max = freqMap[a[i]];
            ele = a[i];
        }
    }

    return ele;

}



int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}


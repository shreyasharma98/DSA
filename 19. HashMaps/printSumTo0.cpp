#include<iostream>
#include<unordered_map>
using namespace std;
void PairSum(int *input, int n) {
    unordered_map<int,int> myMap;
    for(int i = 0;i<n;i++)
    {
        myMap[input[i]]++;
    }
    for(int i = 0;i<n;i++)
    {
        int find = -input[i];
        if(myMap.count(find) > 0 && myMap.count(input[i]) > 0)
        {
            for(int j = 0;j<myMap[find]*myMap[input[i]];j++)
            {
                cout<<min(find,input[i])<<" "<<max(find,input[i])<<endl;
            }

            myMap.erase(find);
            myMap.erase(input[i]);
        }
    }

}


int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}

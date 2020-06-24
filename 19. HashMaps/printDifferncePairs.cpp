#include <vector>
#include<iostream>
#include<iterator>
#include<unordered_map>
using namespace std;
void printPairs(int *input, int n, int k) {
	unordered_map<int,int> map1;
	for(int i = 0;i<n;i++)
	{
	    map1[input[i]]++;
	}

	unordered_map<int,int>::iterator it = map1.begin();
	while(it!=map1.end())
    {
        int curr = it->first;
        int upper = curr+k;
        int lower1 = curr-k;
        if(k == 0)
        {
            int a = map1[curr];
            int ctr = (a*(a-1))/2;
            for(int i = 0;i<ctr;i++)
            {
                cout<<curr<<" "<<curr<<endl;
            }
            return;
        }
        else
        {
            if(map1.count(upper) > 0)
            {
                for(int i = 0;i<map1[upper]*map1[curr];i++)
                {
                    cout<<min(upper,curr)<<" "<<max(upper,curr)<<endl;

                }
            }
            if(map1.count(lower1) > 0)
            {
                for(int i = 0;i<map1[lower1]*map1[curr];i++)
                {
                    cout<<min(lower1,curr)<<" "<<max(lower1,curr)<<endl;
                }
            }
            map1[curr] = 0;
        }
        it++;
    }
}



int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}


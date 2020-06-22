#include<queue>
#include<vector>
#include<iostream>
using namespace std;
class triplets
{
    public:
    int data;
    int index;
    int arrayNumber;
};
class cmp
{
public:
    bool operator()(triplets &a,triplets &b)
    {
        return a.data > b.data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    vector<int> output;
    triplets ans;
   priority_queue<triplets, vector<triplets>, cmp > pq;
   for(int i = 0; i < input.size(); i++)
    {
        triplets ans;
        ans.data = input[i]->at(0);
        ans.index = 0;
        ans.arrayNumber = i;
        pq.push(ans);
    }
    while (pq.empty() == false) {
        triplets curr = pq.top();
        pq.pop();

        int i = curr.arrayNumber;
        int j = curr.index;

        output.push_back(curr.data);

        // The next element belongs to same array as
        // current.
        if (j + 1 < input[i]->size())
        {
            triplets ans;
            ans.data = input[i]->at(j+1);
            ans.index = j+1;
            ans.arrayNumber = i;
            pq.push(ans);
        }
    }
    return output;
}
int main() {

	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
    vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	return 0;
}


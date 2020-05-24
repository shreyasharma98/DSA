#include<iostream>
#include<stack>
using namespace std;
int* stockSpan(int *price, int size) {
    int *arr = new int[size];
    arr[0] = 1;
    int prev = 0;
    int max = price[0];
    stack<int> s;
    s.push(0);
    for(int i = 1;i<size;i++)
    {
        if(price[i] < price[s.top()])
        {
            arr[i] = i-prev;
            s.push(i);
            prev = i;
        }
        else
        {
            if(price[i]>max)
            {
                max = price[i];
                while(!s.empty())
                {
                    s.pop();
                }
                arr[i] = i+1;
                s.push(i);
                prev = i;
            }
            else
            {
                arr[i] = i-s.top();
                s.push(i);
                prev = i;
            }

        }

    }
    return arr;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}

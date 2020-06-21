#include<iostream>
using namespace std;
bool checkMaxHeap(int arr[], int n){


    for(int i = 0;i<n;i++)
    {
         int parent = i;
    	int left = (2*parent) +1;
    	int right = (2*parent) +2;
        if(left > n || right > n)
        {
            continue;
        }
        if(arr[left] > arr[parent] || arr[right] > arr[parent])
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    delete [] arr;
}

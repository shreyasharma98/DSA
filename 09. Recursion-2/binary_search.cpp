#include <iostream>
using namespace std;

int binarySearchhelper(int input[],int start,int end,int element)
{
    if(start<=end)
    {
        int mid = (start+end)/2;
        if(input[mid] == element)
        {
            return mid;
        }
        if(input[mid] > element)
        {
            return binarySearchhelper(input,start,mid-1,element);
        }

        return binarySearchhelper(input,mid+1,end,element);
    }
    return -1;
}
int binarySearch(int input[], int size, int element) {
    if(size == 0)
    {
        return -1;
    }
 return binarySearchhelper(input,0,size-1,element);
}

int main() {
    int input[500],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    {
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

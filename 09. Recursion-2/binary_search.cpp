#include <iostream>
using namespace std;

int binarySearch(int input[], int size, int element) {
    int mid = (0+size)/2;
    if(element<input[0]||element>input[size-1])
    {
        return -1;
    }
    if(input[mid] == element)
    {
        return mid;
    }

    else if(input[mid] < element)
        {
            return (mid+1)+binarySearch(input+mid+1,size-mid-1,element);
        }
    else
        {
            return binarySearch(input,mid+1,element);
        }
    }

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    {
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

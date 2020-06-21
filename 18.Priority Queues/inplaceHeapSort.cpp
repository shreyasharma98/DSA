#include <iostream>
using namespace std;


void swap(int *x, int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
}
void inplaceHeapSort(int input[], int n){
    int i = 1;

    while(i<n)
    {
        int childIndex = i;
        while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(input[childIndex] < input[parentIndex]) {
				swap(&input[childIndex],&input[parentIndex]);
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

        i++;
    }
    while(n>1)
    {
        swap(&input[0],&input[n-1]);
        n--;
        int parent = 0;
        int leftChild = 1+(2*parent);
        int rightChild = 2+(2*parent);
        while(leftChild < n )
        {
            int minIndex=parent;
            if(input[minIndex] > input[leftChild] )
            {
                minIndex = leftChild;
            }
            if(input[minIndex] > input[rightChild] && rightChild < n)
            {
                minIndex = rightChild;
            }

            if(minIndex==parent)
            {
                break;
            }
            swap(&input[minIndex],&input[parent]);
            parent = minIndex;
            leftChild = 1+(2*parent);
            rightChild = 2+(2*parent);
        }

    }
}
int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";

	return 0;
}



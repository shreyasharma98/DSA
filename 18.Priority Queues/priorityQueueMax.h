#include <vector>

class PriorityQueueMax{
     vector<int> pq;

    public :

    PriorityQueueMax() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }

    int getMax() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    void insert(int ele)
    {
        pq.push_back(ele);
        int childIndex = pq.size()-1;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
             childIndex = parentIndex;
        }

    }
    int removeMax() {
        if (isEmpty())
        {
            cout<<"Heap is empty!";
            return 0;
        }
       int remData = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();


        int parent = 0;
        int leftChild = 1+(2*parent);
        int rightChild = 2+(2*parent);

		while((pq[parent] < pq[leftChild] && leftChild < pq.size() )|| ( pq[parent] < pq[rightChild]  && rightChild < pq.size()))
        {
            int minIndex=parent;
            if(pq[minIndex] < pq[leftChild] )
            {
                minIndex = leftChild;
            }
            if(pq[minIndex] < pq[rightChild])
            {
                minIndex = rightChild;
            }

            if(minIndex==parent)
            {
                break;
            }
             int temp = pq[minIndex];
                pq[minIndex] = pq[parent];
                pq[parent] = temp;

            parent = minIndex;
            leftChild = 1+(2*parent);
            rightChild = 2+(2*parent);
        }


    return remData;
      }

};

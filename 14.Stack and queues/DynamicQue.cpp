#include<iostream>
using namespace std;
template <typename T>
class Queue{
 T *data;
 int size;
 int next;
 int first;
 int capacity;
 public :
     Queue()
     {
         data = new T[4];
         first = -1;
         next = 0;
         size = 0;
         this->capacity = 4;
     }

     int getSize()
     {
         return size;
     }
     bool isEmpty()
     {
         return size == 0;
     }
     void enque(T element)
     {
         if(size == capacity)
         {
            T *newData = new T[2*capacity];
            int i = 0;size = 0;
            while(size!=capacity)
            {
                newData[i] = data[first];
                first = (first+1)%capacity;
                i++;size++;
            }
            first = 0;
            next= i;
            delete data;
            data = newData;
            size = capacity;
            capacity *= 2;
         }
         data[next] = element;
         next = (next+1)%capacity;
         size++;
         if(first == -1)
         {
             first = 0;
         }
     }
     T front()
     {
          if(isEmpty())
          {
              cout<<"Queue is Empty!!";
              return 0;
          }
          return data[first];
     }

     T deque()
     {
         if(isEmpty())
          {
              cout<<"Queue is Empty!!";
              return 0;
          }
          T ans = data[first];
          first=(first+1)%capacity;
          size--;
          if(size == 0)
          {
              first = -1;
              next = 0;
          }
         return ans;
     }

};

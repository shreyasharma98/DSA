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
     Queue(int s)
     {
         data = new T[s];
         first = -1;
         next = 0;
         size = 0;
         this->capacity = s;
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
             cout<<"Queue is full";
             return;
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

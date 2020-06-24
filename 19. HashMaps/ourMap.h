#include<string>
using namespace std;
template <typename V>
class Node
{
public:
    string key;
    V value;
    Node* next;

    Node(string k,V x)
    {
        this->key = k;
        this->value = x;
        this->next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};
template <typename V>
class myMap
{
    Node<V>** bucket;
    int ctr;
    int numBuckets;
public:
    myMap()
    {
        ctr = 0;
        numBuckets = 5;
        bucket = new Node<V>*[numBuckets];
       for(int i=0;i<numBuckets;i++)
       {
           bucket[i]=NULL;
       }
    }
    ~myMap()
    {
        for(int i=0;i<ctr;i++)
       {
           delete bucket[i];
       }
       delete [] bucket;
    }
    int getSize()
    {
        return ctr;
    }
    V search(string k)
    {
        int bucketIndex = hashFunction(k);
        Node<V>* head = bucket[bucketIndex];
        while(head!=NULL)
        {
            if(head->key == k)
            {
               return head->value;
            }
            head = head->next;
        }
        return 0;
    }
private:
    int hashFunction(string k)
    {
        int hashCode = 0;
        int currCoef = 1;
        for(int  i= k.length()-1;i>=0;i--)
        {
            hashCode += k[i]*currCoef;
            hashCode = hashCode%numBuckets;
            currCoef *= 37;
            currCoef %= numBuckets;
        }
        return hashCode%numBuckets;
    }
public:
        double get_Load()
    {
        return (1.0*ctr)/numBuckets;
    }
    void rehashing()
    {
        Node<V>** temBucket = bucket;
        bucket = new Node<V>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++)
       {
           bucket[i]=NULL;
       }
        int oldNumBucket = numBuckets;
        numBuckets *= 2;
        ctr = 0;
       for(int i=0;i<oldNumBucket;i++)
       {
           Node<V>* head = temBucket[i];
           while(head!=NULL)
           {
               string k = head->key;
               V x = head->value;
               insert(k,x);
               head=head->next;
           }

       }
       for(int i=0;i<oldNumBucket;i++)
       {
           Node<V>* head = temBucket[i];
           delete head;
       }
       delete temBucket;

    }
    void insert(string key,V val)
    {
        int bucketIndex=hashFunction(key);
        Node<V>* head = bucket[bucketIndex];
        while(head!=NULL)
        {
            if(head->key == key)
            {
                head->value = val;
                return;
            }
            head=head->next;
        }
         head = bucket[bucketIndex];
        Node<V>* newNode = new Node<V>(key,val);
        newNode->next = head;
        bucket[bucketIndex] = newNode;
        ctr++;
        double load = (1.0*ctr)/numBuckets;
        if(load > 0.7)
        {
            rehashing();
        }
    }
    V remove(string k)
    {
        int bucketIndex = hashFunction(k);
        Node<V>* head = bucket[bucketIndex];
        Node<V>* prev = NULL;
        while(head != NULL)
        {
            if(head->key == k)
            {
                if(prev == NULL)
                {
                   bucket[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V x = head->value;
                head->next = NULL;
                delete head;
                ctr--;
                return x;
            }
            prev = head;
            head = head->next;
        }

        return 0;
    }


};

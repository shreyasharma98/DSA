#include<iostream>
#include<unordered_map>
using namespace std;
void intersection(int input1[], int input2[], int size1, int size2) {

    unordered_map<int,int> present;
    if(size1>size2)
    {
        for(int i =0;i<size1;i++)
        {
            present[input1[i]]++;
        }

        for(int i =0;i<size2;i++)
        {

            if(present.count(input2[i]) > 0)
            {
                cout<<input2[i]<<endl;
            }
            present[input2[i]]--;
            if(present.count(input2[i]) == 0)
            {
                present.erase(input2[i]);
            }
        }
    }
    else
    {
        for(int i =0;i<size2;i++)
        {
            present[input2[i]]++;
        }

        for(int i =0;i<size1;i++)
        {

            if(present.count(input1[i]) > 0)
            {
                cout<<input1[i]<<endl;
            }
            present[input1[i]]--;
            if(present.count(input1[i]) == 0)
            {
                present.erase(input1[i]);
            }
        }
    }



}
int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];

	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];

	for(int i=0;i<size2;i++)
		cin>>input2[i];


	intersection(input1,input2,size1,size2);


	return 0;
}

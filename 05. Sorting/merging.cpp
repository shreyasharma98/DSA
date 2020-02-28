
#include<iostream>
using namespace std;


void merge(int arr1[], int size1, int arr2[], int size2, int ans[]){
int i = 0,j=0;
for(int k =0 ;k<size1+size2;k++)
{
    if(i<=size1-1 && j<=size2-1)
       {
            if(arr1[i]<arr2[j])
            {
            ans[k] = arr1[i];
            i++;
            }
            else{
            ans[k] = arr2[j];
            j++;}
       }
    else if(i==size1){
            ans[k] = arr2[j];
            j++;}
    else{
            ans[k] = arr1[i];
            i++;
            }
}

}

int main(){
  int size1;
  cin >> size1;
  int* arr1 = new int[size1];
  for(int i = 0; i < size1; i++){
    cin >> arr1[i];
  }
  int size2;
  cin >> size2;
  int* arr2 = new int[size2];
  for(int i = 0; i < size2; i++){
    cin >> arr2[i];
  }

  int* ans = new int[size1 + size2];

  merge(arr1, size1, arr2, size2, ans);

  for(int i = 0; i < size1 + size2; i++){
			cout << ans[i] <<  " ";
		}
  delete arr1;
  delete arr2;
  delete ans;
}




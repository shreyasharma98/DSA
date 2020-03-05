#include<iostream>
using namespace std;
void findLargest(int input[][10],int row,int col)
{
    int idx , largest = INT_MIN;
    bool IsRow= true;
    for(int i = 0 ;i<row;i++)
    {
        int row_sum = 0;
        for(int j =0;j<col;j++)
        {
            row_sum+= input[i][j];
        }
        if(row_sum > largest)
        {
            largest = row_sum;
            idx = i;
        }
    }
    for(int j = 0 ;j<col;j++)
    {
        int col_sum = 0;
        for(int i =0;i<row;i++)
        {
            col_sum+= input[i][j];
        }
        if(col_sum > largest)
        {
            largest = col_sum;
            idx = j;
            IsRow = false;
        }
    }
    if(IsRow)
    {
        cout<<"row "<<idx<<" "<<largest;
    }
    else
    {
        cout<<"column "<<idx<<" "<<largest;
    }
}
int main() {
    int row, col;
    cin >> row >> col;

    int input[10][10];
    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    findLargest(input, row, col);
}




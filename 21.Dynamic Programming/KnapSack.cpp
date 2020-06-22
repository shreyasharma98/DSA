#include <iostream>
using namespace std;
int knapsackDP(int* weights, int* values, int n, int maxWeight){
    int **arr = new int*[n+1];
    for(int i = 0; i <= maxWeight; i++) {
        arr[i] = new int[maxWeight+1];
    }
    arr[0][0] = 0;
    for(int i = 1;i<=n;i++)
    {
        arr[i][0] = 0;
    }
    for(int i = 1;i<=maxWeight;i++)
    {
        arr[0][i] = 0;
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=maxWeight;j++)
        {
            if(weights[i-1] <= j)
            arr[i][j] = max(arr[i-1][j],arr[i-1][j-weights[i-1]]+values[i-1]);

            else
                arr[i][j] = arr[i-1][j];
         }
    }

    return arr[n][maxWeight];

}



int knapsack(int* weights, int* values, int n, int maxWeight){
	if( n==0 || maxWeight == 0)
    {return 0;}

    if(weights[0] > maxWeight)
    {
        return knapsack(weights+1,values+1,n-1,maxWeight);
    }
    else{
        return max(values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]),knapsack(weights+1,values+1,n-1,maxWeight));
    }
}


int main() {
	int n;
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;
	cout << knapsackDP(weights, values, n, maxWeight) << endl;
}

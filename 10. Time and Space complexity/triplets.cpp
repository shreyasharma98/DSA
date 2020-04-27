#include<iostream>
#include<algorithm>
using namespace std;
int ctr_for_l(int arr[],int idx,int n)   //counts towards right, from idx, exclusding n
{
    int c = 0;
    for(int i = idx;i<n;i++)
    {
        if(arr[i] == arr[idx])
        {
            c++;
        }
    }
    return c;
}

int ctr_for_r(int arr[],int idx,int limit)        //counts towards left, from idx, downtill limit
{
    int c = 1;
    for(int i = idx-1;i>=limit;--i)
    {
        if(arr[i]!=arr[i+1]) break;
		else c++;
    }
    return c;
}




void sum_triplets(int p[],int n, int x)
{
	sort(p,p+n);
	for(int  i = 0;i<n-2;i++)
	{
		int l = i+1,r = n-1;
		while(l<r)
		{
			if(p[i]+p[l]+p[r] == x)
			{
				if(p[i] == p[l] && p[l] == p[r])
				{
					for(int k  = 0;k<r-l;k++)
					{
						cout<<p[i]<<", "<<p[l]<<" and "<<p[r]<<endl;

					}
					l++;
				}
				else if(p[l] == p[r])
				{
					int  ctr_lft = ctr_for_l(p,l,r+1);
					for(int k  = 0;k<ctr_lft*(ctr_lft-1/2);k++)
					{
						cout<<p[i]<<", "<<p[l]<<" and "<<p[r]<<endl;
					}
					l+=ctr_lft;
				}
				else
				{
					int ctr_lft = ctr_for_l(p,l,r);
					int ctr_rt = ctr_for_r(p,r,i+1);
					for(int k  = 0;k<ctr_lft*ctr_rt;k++)
					{
						cout<<p[i]<<", "<<p[l]<<" and "<<p[r]<<endl;
					}
					l+=ctr_lft;
					r-= ctr_rt;
				}
			}
			else if(p[i]+p[l]+p[r] > x)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
	}
}
int main() {
	int n,x;
	cin>>n;
	int *p = new int[n];
	for(int i = 0;i<n;i++)
	{
		cin>>p[i];
	}
	cin>>x;
	sum_triplets(p,n,x);
	delete []p;
	return 0;
}

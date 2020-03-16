void printPatt(int n)
{
    int i = 1;
    while(i<=(n/2)+1)
    {
        int k =1;
        while(k<=(n/2)-i+1)
        {
            cout<<" ";
            k++;
        }
        int j = 1;
        while(j<=2*i -1)
        {
            cout<<"*";
            j++;
        }
        cout<<"\n";
        i++;
    }
  int l = n/2;
    while(l>=1)
    {
        int k = 1;
        while(k<=(n/2)-l+1)
        {
            cout<<" ";
            k++;
        }
        int j = 1;
        while(j<=2*l -1)
        {
            cout<<"*";
            j++;
        }
        cout<<"\n";
        l--;
    }

}




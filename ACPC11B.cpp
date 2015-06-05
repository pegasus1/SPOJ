#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int partition(int * x,int l,int h)
{
    int a=x[l],i=l,temp;
    for(int j=l+1;j<=h;j++)
    {
        if(x[j]<=a)
        {
            i=i+1;
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
        }
    }
    temp=x[l];
    x[l]=x[i];
    x[i]=temp;
    return i;
}


void quicksort(int * x,int l,int h)
{
    int q;
    if(l>=h)
        return;
    q=partition(x,l,h);
    quicksort(x,l,q-1);
    quicksort(x,q+1,h);
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2;
        int arr1[1001],arr2[1001];
        cin>>n1;
        for(int i=0;i<n1;i++)
            cin>>arr1[i];
        quicksort(arr1,0,n1-1);

        cin>>n2;
        for(int i=0;i<n2;i++)
            cin>>arr2[i];
        quicksort(arr2,0,n2-1);

        int ans = INT_MAX;

        int q=0,r=0;
        while(q<n1 && r<n2)
        {
            int x = arr1[q]>arr2[r]?arr1[q] - arr2[r]:arr2[r] - arr1[q];
            ans = fmin(ans,x);
            if(arr1[q]<arr2[r])
                q++;
            else
                r++;
        }
        cout<<ans<<"\n";


    }
    return 0;
}


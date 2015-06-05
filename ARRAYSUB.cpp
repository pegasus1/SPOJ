#include<iostream>
#include<stdio.h>
using namespace std;
int arr[1000001];
int main()
{
    int n,k,pos,y,mx,pmx;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&k);
    mx = arr[0];
    pmx = 0;
    for(int j=0;j<k;j++)
    {
        if(arr[j]>mx)
        {
            pmx = j;
            mx = arr[j];
        }
    }
    printf("%d ",mx);
    for(int i=1;i<=n-k;i++)
    {
        if(arr[i+k-1]>=mx)
        {
            mx = arr[i+k-1];
            pmx = i+k-1;
            printf("%d ",mx);

        }
        else if(pmx>=i)
            printf("%d ",mx);
        else
        {
            mx = arr[i];
            for(int y=0;y<k;y++)
            {
                if(arr[i+y]>=mx)
                {
                    mx = arr[i+y];
                    pmx = i+y;
                }
            }
            printf("%d ",mx);
        }
    }
    return 0;
}


#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[100001];
    while(t--)
    {
        int n;
        int x = 0;
        int sum=0;
        int ans = INT_MAX;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum = sum + arr[i];
        }
        for(int i=0;i<n-1;i++)
        {
            x += arr[i];
            int y = x +  sum - arr[i+1];
            if(i==n-2)
                y = y/2;
            ans = min(ans,y);
        }

        x=0;
        for(int i=n-1;i>0;i--)
        {
            x += arr[i];
            int y = x +  sum - arr[i-1];
            if(i==1)
                y = y/2;
            ans = min(ans,y);
        }
        printf("%d\n",ans);

    }
    return 0;
}


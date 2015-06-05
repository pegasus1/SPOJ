#include<iostream>
#define large 100000
using namespace std;
#include<limits.h>
void print(int ** dp,int n,int k)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}


void utilfun(int * cost, int n, int k)
{

    int ** dp = new int*[n];
    for(int i=0; i<n; i++)
        dp[i] = new int[k];

    //print(dp,n,k);

    for(int i=0;i<k;i++)
    {
        if(cost[i]==-1)
            dp[0][i] = large;
        else
            dp[0][i] = cost[i];
    }



    for(int x=1;x<n;x++)
    {
        for(int y=0;y<k;y++)
            dp[x][y] = large;
    }

    for(int m=1;m<n;m++)
    {
        for(int n=1;n<k;n++)
        {
            int min = large;
            for(int i=0; i<=m/2; i++)
            {
                for(int j=0; j<=n/2; j++)
                {
                    int t = dp[i][j] + dp[m-i-1][n-j-1];
                    if(t<min)
                        min = t;
                }
            }
            if(min>=large)
                dp[m][n] = large;
            else
                dp[m][n] = min;
        }
    }
    //print(dp,n,k);
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(dp[i][k-1]<ans)
            ans = dp[i][k-1];
    }
    if(ans==large)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int * cost = new int[k];
        for(int i= 0; i<k; i++)
            cin>>cost[i];
        utilfun(cost,n,k);
    }
    return 0;
}


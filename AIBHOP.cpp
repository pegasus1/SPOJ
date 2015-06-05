#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;
int dp[2][6101];
int lcs(char X[],int n)
{
   int i, j;
   for(i=1;i<=n;i++)
   {
        for(j=1;j<=n;j++)
        {
            if(X[i-1] == X[n-j])
                dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
            else
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
        }
   }
    return dp[n%2][n];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        char a[6101];
        cin>>a;
        int n = strlen(a);
        int z = lcs(a,n);
        cout<<n-z<<endl;
    }
    return 0;
}


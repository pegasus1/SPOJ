#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<cmath>
#include<stdlib.h>
int main()
{
    int t;
    int arr[501][501],dp[501][501];
    scanf("%d",&t);
    while(t--)
    {
        int r,c,i,j;
        scanf("%d %d",&r,&c);

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                scanf("%d",&arr[i][j]);
        }

        dp[r-1][c-1]=0;

        for(i=c-2;i>=0;i--)
            dp[r-1][i] = fmin( arr[r-1][i], arr[r-1][i]+dp[r-1][i+1] );

        for(i=r-2;i>=0;i--)
            dp[i][c-1] = fmin( arr[i][c-1], arr[i][c-1]+dp[i+1][c-1] );

        for(i=r-2;i>=0;i--)
        {
            for(j=c-2;j>=0;j--)
            {
                int a,b;
                a = fmin(arr[i][j], arr[i][j]+dp[i][j+1]);
                b = fmin(arr[i][j], arr[i][j]+dp[i+1][j]);
                dp[i][j] = fmax(a,b);
            }
        }

        /*for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }*/

        if(dp[0][0]<1)
            printf("%d\n",1-dp[0][0]);
        else
            printf("%d\n",1);
    }
    return 0;
}


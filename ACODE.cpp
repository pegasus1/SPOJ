#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char a[5001];
    int dp[5001];
    scanf("%s",a);
    while(a[0]!='0')
    {
        int i,d,l = strlen(a);
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        dp[-1] = 0;
        d = a[0]-'0';
        for(i=1;i<l;i++)
        {
            int x = a[i]-'0';
            int z = d*10+x;
            if(x)
                dp[i] = dp[i-1];
            if(z<=26 && z>9)
                dp[i] += (i-2>=0?dp[i-2]:1);
            d = x;
        }
        printf("%d\n",dp[l-1]);
        scanf("%s",a);
    }
    return 0;
}


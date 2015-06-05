#include<iostream>
using namespace std;
#include<stdio.h>
int main()
{
    int t;
    unsigned long long n,st,lt,i,sum,p,s1;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%llu",&n);
        if(n<=3)
            printf("%d\n",n-1);
        else
        {
            for(i=2;i*i<=n;i++)
            {
                p = n/i;
                sum+=(p-1)*i;
                st = p+1;
                lt = n/(i-1);
                s1 = ((lt-st+1)*(st+lt))/2;
                s1 = s1 * (i-2);
                sum = sum+s1;
            }
            for(;i<st;i++)
            {
                p = n/i;
                sum = sum + (p-1)*i;
            }
            sum+=n-1;
            printf("%llu\n",sum);
        }
    }
    return 0;
}


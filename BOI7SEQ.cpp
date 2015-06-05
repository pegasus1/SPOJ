#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    unsigned long long int prev,cur,ans=0;
    scanf("%d",&n);
    scanf("%llu",&prev);
    for(int i=1;i<n;i++)
    {
        scanf("%llu",&cur);
        ans = ans + max(prev,cur);
        prev = cur;
    }
    printf("%llu\n",ans);
    return 0;
}


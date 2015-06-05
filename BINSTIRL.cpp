#include<stdio.h>
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        int f;
        scanf("%d %d",&n,&k);
        f = (n-k)&((k-1)/2);
        if(f==0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}


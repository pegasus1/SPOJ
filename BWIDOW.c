#include<stdio.h>
#include<limits.h>
int inner[1001];
int outer[1001];
int main()
{
    int t,n;
    int mir;
    scanf("%d",&t);
    while(t--)
    {
        int n,pos,flag=1,i;
        mir = INT_MIN;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&inner[i],&outer[i]);
            if(inner[i]>mir)
            {
                mir = inner[i];
                pos = i;
            }
        }

        for(i=0;i<n;i++)
        {
            if(i!=pos && outer[i]>=mir)
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("%d\n",pos+1);
        else
            printf("-1\n");

    }
    return 0;
}


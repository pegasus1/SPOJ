#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        if((n-1)%3!=0)
            printf("N\n");
        else
        {
            int c = (n-1)/3;
            float d = (1+sqrt(1+4*c))/2;
            if(d-(int)(d)==0)
                printf("Y\n");
            else
                printf("N\n");
        }
        scanf("%d",&n);
    }
    return 0;
}


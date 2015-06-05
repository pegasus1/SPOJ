#include<stdio.h>
#include<malloc.h>
int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int t;
    do
    {
        int i,j,x,y,s1=0,s2=0,ans=0;
        scanf("%d",&i);
        if(i==0)
            break;
        int * arr1 = malloc((i+1)*sizeof(int));
        for(x=0;x<i;x++)
            scanf("%d",&arr1[x]);

        scanf("%d",&j);
        int * arr2 = malloc((j+1)*sizeof(int));
        for(y=0;y<j;y++)
            scanf("%d",&arr2[y]);

        arr1[i] = 10001;
        arr2[j] = 10001;
        x = 0;
        y = 0;
        while(x<=i || y<=j)
        {
            while(arr1[x]!=arr2[y])
            {
                while(arr1[x]<arr2[y])
                    s1 += arr1[x++];

                while(arr1[x]>arr2[y])
                    s2 += arr2[y++];
            }
            ans = ans + max(s1,s2) + arr1[x];
            x++;
            y++;
            s1 = s2 = 0;

        }
        ans = ans + max(s1,s2);
        printf("%d\n",ans-10001);
    }while(1);
    return 0;
}


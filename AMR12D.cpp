#include<stdio.h>
#include<string.h>
#include<algorithm>
int check(char * a,int l)
{
    int s = 0;
    int x = l-1;
    while(s<x)
    if(a[s]!=a[x])
        return 0;
    else
    {
        s++;
        x--;
    }
    return 1;
}

int main()
{
    int t,l;
    char s[11];
    scanf("%d",&t);
    while(t--)
    {
        int u;
        scanf("%s",s);
        l = strlen(s);
        u = check(s,l);
        if(u==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


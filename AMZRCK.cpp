#include<stdio.h>
#include<iostream>
using namespace std;
long long fib[45];
int main()
{
    int t,n;
    fib[0]=1;
    fib[1]=2;
    for(int i=2;i<45;i++)
        fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",fib[n]);
    }
    return 0;
}


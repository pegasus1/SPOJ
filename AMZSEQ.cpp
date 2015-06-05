#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int x=3,t=1;
    for(int i=1;i<n;i++)
    {
        int z = x;
        x=2*x+t;
        t=z;
    }
    printf("%d\n",x);
    return 0;
}


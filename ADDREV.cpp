#include<iostream>
using namespace std;
long int reverse(long int h)
{
    long int g=0;
    while(h>0)
    {
        int b=h%10;
        g=g*10+b;
        h=h/10;
    }
    return g;
}

int main()
{
    int n;
    cin>>n;
    long int x,y;
    for(int g=0;g<n;g++)
    {
        cin>>x>>y;
        cout<<reverse(reverse(x)+reverse(y))<<"\n";
    }
    return 0;
}


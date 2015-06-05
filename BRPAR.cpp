#include<iostream>
using namespace std;
unsigned long long int fact[2002];

unsigned long long int exp(unsigned long long int x,unsigned long long int y)
{
    unsigned long long int pro;
    if(y==0)
        return 1;
    if(y==1)
        return x;
    else if(y%2==0)
    {
        pro=exp(x,y/2);
        pro=(pro*pro)%1000000007;
    }
    else
    {
        pro=exp(x,(y-1)/2);
        pro=(((pro*pro)%1000000007)*x)%1000000007;
    }
    return pro%1000000007;
}



void initialize()
{
    fact[0]=1;
    for(int i=1;i<2002;i++)
        fact[i]=(fact[i-1]*i)%1000000007;
    /*(for(int i=1;i<100;i++)
        cout<<i<<" : "<<fact[i]<<endl;*/
}


int main()
{
    int t;
    cin>>t;
    initialize();
    while(t--)
    {
        unsigned long long int n,x=0,den=1,num=1,inv;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int y;
            cin>>y;
            den = (den*fact[y])%1000000007;
            x = x+y;
        }
        den = (den*fact[x+1])%1000000007;
        num = fact[2*x];
        inv = exp(den,1000000005);
        //cout<<num<<" "<<den<<" "<<inv<<endl;
        cout<<(num*inv)%1000000007<<endl;
    }
    return 0;
}


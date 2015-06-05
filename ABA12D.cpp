#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
long long power(long long a, long long b)
{
    long long z;
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    else if(b%2==1)
    {
        z = power(a,b/2);
        return z*z*a;
    }
    else if(b%2==0)
    {
        z = power(a,b/2);
        return z*z;
    }
}

bool isPrime(long long z)
{
    bool isprime = true;
    if(z==2)
        return true;
    for(int i=2;i*i<=z;i++)
    {
        if(z%i==0)
            return false;
    }
    return true;
}




int main()
{
    int t,a,b;
    long long k;
    long long z,m;
    map<long,long> m1;
    m1[2] = 1;
    map<long,long> :: iterator it;
    for(long long i=2;i<1000;i++)
    {
        if(isPrime(i))
        {
            k = 2;
            long long h = power(i,k);
            while(h<=1000000)
            {
                m = power(i,k+1);
                z = (power(i,k+1)-1)/(i-1);
                if(isPrime(z))
                    m1[h]=1;
                k = k + 2;
                h = power(i,k);
            }
        }
    }

    int ans;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>a>>b;
        for(it=m1.begin();it!=m1.end();it++)
        {
            if(a<=it->first && it->first<=b)
                ans++;
        }
        cout<<ans<<endl;
    }
}


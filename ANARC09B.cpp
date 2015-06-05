#include<iostream>
using namespace std;
#include<math.h>

long long int gcd(long long int n1,long long int n2)
{
  if(n1==0)
    return n2;
  else if(n2==0)
    return n1;
  if(n1>n2)
    return gcd(n1%n2,n2);
  else
    return gcd(n1,n2%n1);
   return 0;
}

int main()
{
    long long i,j,k,lcm;
    long long W,H;
    cin>>W>>H;
    while(W!=0)
    {
        if(W==0 && H==0)
            break;
        if(W==H)
            cout<<"1\n";
        else if(W>H)
        {
            if(W%H==0)
                cout<<W/H<<"\n";
            else
                cout<<((W*H)/gcd(W,H))<<"\n";
        }
        else if(H>W)
        {
            if(H%W==0)
                cout<<H/W<<"\n";
            else
                cout<<(W*H)/gcd(W,H)<<"\n";
        }
    cin>>W>>H;
    }
    return 0;
}


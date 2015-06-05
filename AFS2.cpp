#include<iostream>
#include<string.h>
using namespace std;
#include<stdio.h>
int arr[30];
int add[30];
int count[2];
int k;
void makearr(unsigned long long n)
{
    k=0;
    while(n>0)
    {
        arr[k++]=n%10;
        n=n/10;
    }
}

void makeadd(unsigned long long n)
{
    count[1]=0;
    while(n>0)
    {
        add[(count[1])++]=n%10;
        n=n/10;
    }
}

void print()
{
    for(int i=k-1; i>=0; i--)
        printf("%d",arr[i]);
}

void summify()
{
    count[0]=k;
    k = 0;
    int carry = 0;
    int i=0,j=0;
    for(; i<count[0] && j<count[1]; i++,j++)
    {
        int b = arr[i];
        arr[k++]=(arr[i]+add[j]+carry)%10;
        carry = (b+add[j]+carry)/10;
    }
    while(i<count[0])
    {
        int b = arr[i];
        arr[k++]=(arr[i]+carry)%10;
        carry = (b+carry)/10;
        i++;
    }
    while(j<count[1])
    {
        int b = add[j];
        arr[k++]=(add[j]+carry)%10;
        carry = (b+carry)/10;
        j++;
    }
    if(carry!=0)
        arr[k++]=1;

}

int main()
{
    int t,q;
    unsigned long long sum,st,lt,i,n,r,s1,s2,p;
    unsigned long long limit = 1000000000;
    scanf("%d",&t);
    while(t--)
    {
        int madearray=0;
        scanf("%llu",&n);
        if(n<=3)
            printf("%llu\n",n-1);
        else
        {
            sum = 0;
            sum+=n-1;
            for(i=2; i*i<=n; i++)
            {
                p = n/i;
                st = p+1;
                lt = n/(i-1);
                s1 = ((lt-st+1)*(st));
                s2 = ((lt-st+1)*(lt));
                s1=(s1*(i-2))/2;
                s2=(s2*(i-2))/2;
                if(lt%2==1 && st%2==1 && i%2==1)
                    q=1;
                else
                    q=0;
                if(sum>limit)
                {
                    if(!madearray)
                    {
                        makearr(sum);
                        madearray=1;
                    }
                    r = (p-1)*i+q;
                    makeadd(s1);
                    summify();
                    makeadd(s2);
                    summify();
                    makeadd(r);
                    summify();
                }
                else
                    sum+=(p-1)*i+s1+s2+q;

            }
            for(; i<st; i++)
            {
                p = n/i;
                if(sum>limit)
                {
                    r = (p-1)*i;
                    if(!madearray)
                    {
                        makearr(sum);
                        madearray=1;
                    }
                    makeadd(r);
                    summify();
                }
                else
                    sum+=(p-1)*i;
            }

            if(sum<=limit)
                printf("%llu\n",sum);
            else
            {
                print();
                printf("\n");
            }
        }
    }
    return 0;
}



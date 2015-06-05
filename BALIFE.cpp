#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=-1)
    {
        int sum = 0;
        int * arr = new int[n];
        int * dt = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum = sum + arr[i];
        }
        if(sum%n!=0)
            cout<<"-1\n";
        else if(n==1)
            cout<<"0\n";
        else
        {

            int avg = sum/n;
            dt[0] = arr[0]-avg;
            for(int i=1;i<n;i++)
                dt[i] = arr[i] + dt[i-1] - avg;
            int ans = dt[0];
            for(int i=0;i<n;i++)
            {
                if(dt[i]<0)
                    dt[i] = (-1)*dt[i];
                if(dt[i]>ans)
                    ans = dt[i];
            }
            cout<<ans<<"\n";
        }
        cin>>n;
    }
    return 0;
}


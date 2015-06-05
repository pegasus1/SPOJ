#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
    int ans;
    int t,k,n,x;
    vector<int> v;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        ans = INT_MAX;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        if(k==1)
            printf("0\n");
        else
        {
            sort(v.begin(),v.end());
            for(int i=0;i<=n-k;i++)
            {
                int alt = v[i+k-1]-v[i];
                ans = min(ans,alt);
            }
            cout<<ans<<endl;
        }
    }
    return 0;

}


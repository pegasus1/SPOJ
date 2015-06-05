#include<iostream>
using namespace std;
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
char arr[51][51];
bool visited[51][51];
int a1[2500][2];

int max(int a,int b, int c, int d, int e, int f, int g, int h)
{
    int a1 = a>b?a:b;
    int a2 = c>d?c:d;
    int a3 = e>f?e:f;
    int a4 = g>h?g:h;
    int a5 = a1>a2?a1:a2;
    int a6 = a3>a4?a3:a4;
    return a5>a6?a5:a6;

}

int dfs(int i, int j, int r, int c)
{
    //cout<<i<<" "<<j<<endl;
    visited[i][j] = 1;
    int a,b,q,d,e,f,g,h;
    a=b=q=d=e=f=g=h=INT_MIN;
    if(j-1>=0 && arr[i][j-1] == arr[i][j]+1 && !visited[i][j-1])
        a = 1 + dfs(i,j-1,r,c);
    if(i+1<=r && j-1>=0 && arr[i+1][j-1] == arr[i][j]+1 && !visited[i+1][j-1])
        b = 1 + dfs(i+1,j-1,r,c);
    if(i+1<=r && arr[i+1][j] == arr[i][j]+1 && !visited[i+1][j])
        q = 1 + dfs(i+1,j,r,c);
    if(i+1<=r && j+1<=c && arr[i+1][j+1] == arr[i][j]+1 && !visited[i+1][j+1])
        d = 1 + dfs(i+1,j+1,r,c);
    if(j+1<=c && arr[i][j+1] == arr[i][j]+1 && !visited[i][j+1])
        e = 1 + dfs(i,j+1,r,c);
    if(i-1>=0 && j+1<=c && arr[i-1][j+1] == arr[i][j]+1 && !visited[i-1][j+1])
        f = 1 + dfs(i-1,j+1,r,c);
    if(i-1>=0 && arr[i-1][j] == arr[i][j]+1 && !visited[i-1][j])
        g = 1 + dfs(i-1,j,r,c);
    if(i-1>=0 && j-1>=0 && arr[i-1][j-1] == arr[i][j]+1 && !visited[i-1][j-1])
        h = 1 + dfs(i-1,j-1,r,c);
    int k = max(a,b,q,d,e,f,g,h);
    return 1>k?1:k;

}


int main()
{
    int t,n;
    long long x;
    long long sum;
    long long ans;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n;
        if(n!=0)
        {
           cin>>x;
           sum = x;
        }
        for(int i=1;i<n;i++)
        {
            cin>>x;
            ans = ans + (x*i-sum);
            sum+=x;
        }
        cout<<ans<<endl;
    }
}


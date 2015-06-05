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
    int r,c,ans;
    char d;
    int cv;
    scanf("%d %d",&r,&c);
    scanf("%c",&d);
    int count = 0;
    while(r!=0 && c!=0)
    {
        cv = 0;
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
        count++;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                scanf("%c",&arr[i][j]);
                if(arr[i][j]=='A')
                {
                    a1[cv][0] = i;
                    a1[cv][1] = j;
                    cv++;
                }
            }
            scanf("%c",&d);
        }

        ans = 0;
        for(int x = 0; x<cv; x++)
        {
            int i = a1[x][0];
            int j = a1[x][1];
            ans = max(ans,dfs(i,j,r,c));
        }

        printf("Case %d: %d\n",count,ans);

        scanf("%d %d",&r,&c);
        scanf("%c",&d);

    }
}


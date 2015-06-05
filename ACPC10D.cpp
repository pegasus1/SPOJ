#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<limits.h>

int min3(int a,int b,int c)
{
    int x = fmin(a,b);
    return fmin(x,c);
}

int min4(int a,int b,int c,int d)
{
    int x = fmin(a,b);
    int y = fmin(c,d);
    return fmin(x,y);
}


int main()
{
    int arr[100001][3];
    int n;
    int count=1;
    cin>>n;
    while(n!=0)
    {
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
                cin>>arr[i][j];
        }

        arr[0][2] += arr[0][1];
        arr[1][0] = arr[0][1] + arr[1][0];
        arr[1][1] = min3(arr[0][1],arr[0][2],arr[1][0]) + arr[1][1];
        arr[1][2] = min3(arr[0][2],arr[0][1],arr[1][1]) + arr[1][2];
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                    arr[i][j] = fmin(arr[i-1][j],arr[i-1][j+1]) + arr[i][j];
                else if(j==1)
                    arr[i][j] = min4(arr[i-1][j-1],arr[i-1][j],arr[i-1][j+1],arr[i][j-1]) + arr[i][j];
                else if(j==2)
                    arr[i][j] = min3(arr[i-1][j],arr[i-1][j-1],arr[i][j-1]) + arr[i][j];
            }
        }
        cout<<count<<". "<<arr[n-1][1]<<"\n";
        cin>>n;
        count++;
    }

    return 0;
}


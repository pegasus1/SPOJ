#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int g,mg,a;
        int g_max = INT_MIN, mg_max=INT_MIN;
        cin>>g>>mg;
        for(int i=0;i<g;i++)
        {
            cin>>a;
            g_max = max(g_max,a);
        }

        for(int i=0;i<mg;i++)
        {
            cin>>a;
            mg_max = max(mg_max,a);
        }

        if(g_max>=mg_max)
            cout<<"Godzilla\n";
        else if(g_max<mg_max)
            cout<<"MechaGodzilla\n";
    }
    return 0;
}


#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;

int main()
{
    int i=0,count;
    char str[2005];
    while(++i)
    {
        stack<char> s;
        cin>>str;
        if(str[0]=='-')
            exit(0);
        count=0;
        for(int j=0;str[j]!='\0';j++)
        {
            if(str[j]=='}')
            {
                if(!s.empty())
                    s.pop();
                else
                {
                    s.push('{');
                    count++;
                }
            }
            else
                s.push('{');
        }
        if(!s.empty())
            count=count+(s.size()/2);
        cout<<i<<". "<<count<<endl;
    }
    return 0;
}


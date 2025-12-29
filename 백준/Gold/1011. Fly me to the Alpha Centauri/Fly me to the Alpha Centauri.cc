#include <iostream>

using namespace std;

int T;
long long x,y,ret;

void input()
{
    cin>>x>>y;
}

void solve()
{
    x=y-x;
    
    int temp=1;
    while(1)
    {
        x-=2*temp;
        if(x<=0)
        {
            if(x<=-temp)
                ret=2*temp-1;
            else
                ret=2*temp;
            break;
        }

        temp++;
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{   
    cin>>T;
    while(T--)
    {
        input();
        solve();
        printResult();
    }
}
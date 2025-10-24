#include <iostream>

using namespace std;

long long N,ret;

void solve()
{
    while(cin>>N)
    {
        if(N==0) break;
        if(N==1)
        {
            cout<<0<<"\n";
            continue;
        }

        ret=N;

        for(long long i=2;i*i<=N;i++)
        {
            if(N%i==0)
            {
                ret-=ret/i;
                while(N%i==0) N/=i;
            }
        }
        if(N>1) ret-=ret/N;

        cout<<ret<<"\n";
    }
}

int main()
{
    solve();

    return 0;
}
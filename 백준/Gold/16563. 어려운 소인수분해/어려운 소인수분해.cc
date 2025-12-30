#include <iostream>

using namespace std;

int N,M;
int K[1000000];
int spf[5000001];

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>K[i];
        M=max(M,K[i]);
    }
    
    for(int i=2;i<=M;i++)
    {
        if(spf[i]==0)
        {
            spf[i]=i;
            for(long long j=1LL*i*i;j<=M;j+=i)
                if(spf[j]==0)
                    spf[j]=i;
        }
    }
}

void solve()
{
    for(int i=0;i<N;i++)
    {
        while(K[i]!=1)
        {
            int p=spf[K[i]];
            K[i]/=p;
            cout<<p<<" ";
        }    
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
}
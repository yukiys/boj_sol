#include <iostream>

using namespace std;

int T;
int N[100000],M;
int spf[1000001];
long long f[1000001],g[1000001];

void init()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>T;
    for(int t=0;t<T;t++)
    {
        cin>>N[t];
        M=max(M,N[t]);
    }

    spf[1]=1;
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
    f[1]=g[1]=1;
    for(int i=2;i<=M;i++)
    {
        int x=spf[i],cnt=0,temp=i;
        while(temp%x==0)
        {
            cnt++;
            temp/=x;
        }

        long long W=0,w=1;
        for(int j=0;j<=cnt;j++)
        {
            W+=w;
            w*=x;
        }
        f[i]=f[temp]*W;

        g[i]=g[i-1]+f[i];
    }
}

void printRet()
{
    for(int t=0;t<T;t++)
        cout<<g[N[t]]<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}
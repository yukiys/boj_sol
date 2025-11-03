#include <iostream>
#include <vector>

#define MOD 1000000

using namespace std;

int n,a,b,c,base,ret;
int pos[100001];
int pow2[100001];

void input()
{
    cin>>n>>a>>b>>c;
    
    int t;
    for(int i=0;i<a;i++)
    {
        cin>>t;
        pos[t]=1;
        if(t==n) base=1;
    }
    for(int i=0;i<b;i++)
    {
        cin>>t;
        pos[t]=2;
        if(t==n) base=2;
    }
    for(int i=0;i<c;i++)
    {
        cin>>t;
        pos[t]=3;
        if(t==n) base=3;
    }

    pow2[0]=1;
    for(int i=1;i<=n-1;i++)
        pow2[i]=(pow2[i-1]*2)%MOD;
}

void solve()
{
    int to=base,now;
    for(int i=n;i>=1;i--)
    {
        now=pos[i];

        if(now==to) continue;
        else
        {
            ret=(ret+pow2[i-1])%MOD;
            to=6-to-now;
        }
    }
}

void printResult()
{
    cout<<base<<"\n"<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
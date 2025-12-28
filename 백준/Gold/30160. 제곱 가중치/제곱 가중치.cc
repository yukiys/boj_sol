#include <iostream>

using namespace std;

int N;
int a[100001];
long long S[100001],J[100001];
long long ret;

void init()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>a[i];
}

void solve()
{
    for(int i=1;i<=N;i++)
    {
        S[i]=S[i-1]+a[i];
        J[i]=J[i-1]+1LL*(i-1)*a[i];
    }

    for(int i=1;i<=N;i++)
    {
        ret+=1LL*(2*i-1)*S[i]-2LL*J[i];

        cout<<ret<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
}
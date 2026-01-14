#include <iostream>

#define MOD 10007

using namespace std;

int N,ret;
int C[53][53];

void init()
{
    cin>>N;
    C[0][0]=1;
    for(int i=1;i<=52;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
}

void solve()
{
    for(int i=1;i<=13;i++)
    {
        if(N-4*i<0) break;

        int temp=(C[13][i]*C[52-4*i][N-4*i])%MOD;

        if(i%2==1) ret=(ret+temp)%MOD;
        else ret=(ret-temp+MOD)%MOD;
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}
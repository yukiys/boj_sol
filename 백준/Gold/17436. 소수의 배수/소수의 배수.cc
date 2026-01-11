#include <iostream>

using namespace std;

int N;
long long M,ret;
int prime[10];

void init()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>prime[i];
}

void dfs(int idx,long long prod,int depth)
{
    for(int i=idx;i<N;i++)
    {
        int p=prime[i];
        if(prod>M/p) continue;

        long long nprod=prod*p;
        long long add=M/nprod;

        if(depth%2==0) ret+=add;
        else ret-=add;

        dfs(i+1,nprod,depth+1);
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    dfs(0,1,0);
    printRet();
}
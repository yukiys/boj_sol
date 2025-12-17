#include <iostream>

using namespace std;

int N,K,ret;
bool used[101];
int electric[101];

void input()
{
    cin>>N>>K;
    for(int i=1;i<=K;i++) cin>>electric[i];
}

int next(int a)
{
    int Max=0,idx;

    int temp[101];
    for(int i=1;i<=K;i++) temp[i]=101;
    for(int i=a;i<=K;i++)
    {
        if(used[electric[i]] and temp[electric[i]]==101)
        {
            temp[electric[i]]=i;
        }
    }

    for(int i=1;i<=K;i++)
    {
        if(!used[i]) continue;
        
        if(Max<temp[i])
        {
            Max=temp[i];
            idx=i;
        }
    }

    return idx;
}

void solve()
{
    if(N>=K) return;

    int n=0;
    for(int i=1;i<=K;i++)
    {
        int cur=electric[i];
        if(n<N)
        {
            if(!used[cur])
                n++;
            used[cur]=true;
        }
        else
        {
            if(used[cur]) continue;
            ret++;

            used[next(i)]=false;
            used[cur]=true;
        }
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
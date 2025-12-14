#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N;
int H[100001];
int ret[100001];
int near[100001];
int dist[100001];

void input()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>H[i];
}

void solve()
{
    stack<int> S;

    for(int i=1;i<=N;i++)
    {
        while(!S.empty() and H[S.top()]<=H[i])
            S.pop();

        ret[i]+=S.size();
        if(!S.empty())
        {
            int idx=S.top();
            if(near[i]==0)
            {
                dist[i]=i-idx;
                near[i]=idx;
            }
        }

        S.push(i);
    }

    while(!S.empty())
        S.pop();
    for(int i=N;i>=1;i--)
    {
        while(!S.empty() and H[S.top()]<=H[i])
            S.pop();

        ret[i]+=S.size();
        if(!S.empty())
        {
            int idx=S.top();
            if(near[i]==0)
            {
                dist[i]=idx-i;
                near[i]=idx;
            }
            else if(dist[i]>idx-i)
            {
                dist[i]=idx-i;
                near[i]=idx;
            }
        }

        S.push(i);
    }
}

void printResult()
{
    for(int i=1;i<=N;i++)
    {
        if(ret[i]==0) cout<<0<<"\n";
        else cout<<ret[i]<<" "<<near[i]<<"\n";
    }
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
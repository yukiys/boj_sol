#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T,K,ret1,ret2;
string W;
vector<int> Index[26];

void input()
{
    cin>>W;
    cin>>K;
}

void solve()
{
    ret1=10001; ret2=-1;
    for(int i=0;i<26;i++)
        Index[i].clear();

    for(int i=0;i<W.size();i++)
    {
        char c=W[i];
        Index[c-'a'].push_back(i);
    }

    for(int i=0;i<26;i++)
    {
        if(Index[i].size()<K) continue;

        for(int j=0;j+K-1<Index[i].size();j++)
        {
            int temp=Index[i][j+K-1]-Index[i][j]+1;
            ret1=min(ret1,temp);
            ret2=max(ret2,temp);
        }
    }
}

void printResult()
{
    if(ret1==10001)
    {
        cout<<-1<<"\n";
        return;
    }
    cout<<ret1<<" "<<ret2<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>T;
    while(T--)
    {
        input();
        solve();
        printResult();
    }

    return 0;
}
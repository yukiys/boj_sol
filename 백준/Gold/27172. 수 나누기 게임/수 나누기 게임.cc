#include <iostream>
#include <vector>

using namespace std;

int N,M;
int x[100000];
vector<int> exist[1000001];
int ret[100000];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>x[i];
        exist[x[i]].push_back(i);
        M=max(M,x[i]);
    }
}

void solve()
{
    for(int i=0;i<N;i++)
    {
        for(int j=2*x[i];j<=M;j+=x[i])
        {
            if(!exist[j].empty())
            {
                for(int e:exist[x[i]]) ret[e]++;
                for(int e:exist[j]) ret[e]--;
            }
        }
    }
}

void printResult()
{
    for(int i=0;i<N;i++) cout<<ret[i]<<" ";
    cout<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
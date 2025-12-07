#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> v[200001];
priority_queue<long long> pq;
long long ret;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int dead;
        long long prize;
        cin>>dead>>prize;

        v[dead].push_back(prize);
    }
}

void solve()
{
    for(int i=N;i>=1;i--)
    {
        for(int j=0;j<v[i].size();j++)
            pq.push(v[i][j]);

        if(pq.empty()) continue;

        ret+=pq.top();
        pq.pop();
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}
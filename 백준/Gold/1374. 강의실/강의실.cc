#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;
vector<pair<ll,ll>> T;
priority_queue<ll,vector<ll>,greater<ll>> pq;

void init()
{
    cin>>N;
    T.reserve(N);

    for(int i=0;i<N;i++)
    {
        long long id,a,b;
        cin>>id>>a>>b;
        T.push_back({a,b});
    }
}

void solve()
{
    sort(T.begin(),T.end());
    
    for(auto[start,end]:T)
    {
        if(!pq.empty() and pq.top()<=start) pq.pop();
        pq.push(end);
    }
}

void printRet()
{
    cout<<pq.size()<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printRet();
}
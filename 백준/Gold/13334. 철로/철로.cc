#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,d,ret;
vector<pair<int,int>> ho;
priority_queue<int,vector<int>,greater<int>> pq;

void input()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int h,o;
        cin>>h>>o;

        ho.push_back({max(h,o),min(h,o)});
    }
    cin>>d;
}

void solve()
{
    sort(ho.begin(),ho.end());
    
    for(int i=0;i<n;i++)
    {
        int e=ho[i].first;
        int s=ho[i].second;

        if(e-s>d) continue;

        pq.push(s);
        while(!pq.empty() and pq.top()<e-d)
            pq.pop();

        ret=max(ret,(int)pq.size());
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
}
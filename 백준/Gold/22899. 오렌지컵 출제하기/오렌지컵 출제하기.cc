#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,K,p;
pair<int,int> ab[100000];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int check[100001];

void input()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        cin>>ab[i].first;
        if(check[ab[i].first]==0)
        {
            check[ab[i].first]=1;
            p++;
        }
    }
    for(int i=0;i<N;i++) cin>>ab[i].second;

    for(int i=0;i<N;i++) pq.push({ab[i].second,ab[i].first});
}

void solve()
{
    for(int L=1;L<=N;L++)
    {
        if(p*L<K)
        {
            cout<<-1<<" ";
            continue;
        }

        memset(check,0,sizeof(check));
        long long ret=0;
        int count=0;
        vector<pair<int,int>> temp;

        while(count<K)
        {
            int b=pq.top().first;
            int a=pq.top().second;
            temp.push_back({b,a});
            pq.pop();

            if(check[a]<L)
            {
                check[a]++;

                ret+=b;
                count++;
            }
        }
        cout<<ret<<" ";

        for(int i=0;i<temp.size();i++)
            pq.push({temp[i].first,temp[i].second});
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    solve();
    cout<<"\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,C,M,ret;
vector<pair<pair<int,int>,int>> boxes;
int capacity[2000];

void init()
{
    cin>>N>>C;
    for(int i=1;i<=N-1;i++)
        capacity[i]=C;

    cin>>M;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        boxes.push_back({{b,a},c});
    }

    sort(boxes.begin(),boxes.end());
}

void solve()
{
    for(int i=0;i<boxes.size();i++)
    {
        int b=boxes[i].first.first;
        int a=boxes[i].first.second;
        int c=boxes[i].second;

        int m=C;
        for(int j=a;j<=b-1;j++)
            m=min(m,capacity[j]);

        c=min(c,m);
        for(int j=a;j<=b-1;j++)
            capacity[j]-=c;

        ret+=c;
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printRet();
}
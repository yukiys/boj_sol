#include <iostream>
#include <algorithm>

using namespace std;

int N,C,ret;
int x[200000];

void input()
{
    cin>>N>>C;
    for(int i=0;i<N;i++) cin>>x[i];
}

bool can(int dist)
{
    int cnt=1;
    int last=x[0];
    
    for(int i=1;i<N;i++)
    {
        if(x[i]-last>=dist)
        {
            cnt++;
            last=x[i];
        }
    }

    return cnt>=C;
}

void solve()
{
    sort(x,x+N);
    int low=1;
    int high=x[N-1]-x[0];

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(can(mid))
        {
            ret=mid;
            low=mid+1;
        }
        else high=mid-1;
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
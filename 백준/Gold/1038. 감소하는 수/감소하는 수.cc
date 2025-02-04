#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> v;

void dfs(int n,long long add)
{
    v.push_back(add);
    for(int i=n-1;i>=0;i--)
        dfs(i,add*10+i);
}

int main()
{
    for(int i=0;i<10;i++) dfs(i,i);
    sort(v.begin(),v.end());

    cin>>N;
    if(N>=1023) cout<<"-1\n";
    else cout<<v[N]<<"\n";

    return 0;
}
#include <iostream>

using namespace std;

long long A,B;
int ans;

void dfs(int n,int cnt)
{
    if(cnt>=10 or n>B) return;
    
    if(n>=A) ans++;

    dfs(n*10+4,cnt+1);
    dfs(n*10+7,cnt+1);
}

int main()
{
    cin>>A>>B;

    dfs(0,0);

    cout<<ans<<"\n";

    return 0;
}
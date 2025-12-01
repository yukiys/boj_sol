#include <iostream>
#include <stack>

using namespace std;

int N;
long long ret;
long long H[80000];
stack<long long> S;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>H[i];
}

void solve()
{
    for(int i=0;i<N;i++)
    {
        while(!S.empty() and H[i]>=S.top()) S.pop();

        ret+=S.size();
        S.push(H[i]);
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
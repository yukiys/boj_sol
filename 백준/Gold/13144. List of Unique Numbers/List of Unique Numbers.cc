#include <iostream>

using namespace std;

int N;
long long ret;
int A[100000];
bool visited[100001];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
}

void solve()
{
    int r=0;
    for(int l=0;l<N;l++)
    {
        while(r<N)
        {
            if(!visited[A[r]]) visited[A[r++]]=true;
            else break;
        }
        ret+=(r-l);

        visited[A[l]]=false;
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
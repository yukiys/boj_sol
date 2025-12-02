#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const long long LIMIT=(1LL<<31);

using namespace std;

int K,N;
long long ret;
int prime[100];
priority_queue<long long,vector<long long>,greater<long long>> pq;

void input()
{
    cin>>K>>N;
    for(int i=0;i<K;i++)
    {
        cin>>prime[i];
    }
}

void solve()
{
    sort(prime,prime+K);
    for(int i=0;i<K;i++)
        pq.push(prime[i]);

    for(int i=0;i<N;i++)
    {
        long long x=pq.top();
        pq.pop();
        ret=x;

        for(int j=0;j<K;j++)
        {
            long long p=prime[j];

            if(x>LIMIT/p) break;

            pq.push(x*p);
            if(x%p==0) break;
        }
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
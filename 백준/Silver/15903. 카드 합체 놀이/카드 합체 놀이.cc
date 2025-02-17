#include <iostream>
#include <queue>

using namespace std;

int n,m;

int main()
{
    cin>>n>>m;
    
    priority_queue<long long> pq;
    for(int i=0;i<n;i++)
    {
        long long a; cin>>a;
        pq.push(-a);
    }

    for(int i=0;i<m;i++)
    {
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();

        pq.push(a+b);
        pq.push(a+b);
    }

    long long sum=0;
    for(int i=0;i<n;i++)
    {
        long long a=pq.top();
        pq.pop();
        sum+=a;
    }

    cout<<-sum<<"\n";

    return 0;
}
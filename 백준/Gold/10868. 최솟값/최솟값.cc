#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int N,M;
vector<long long> A;
vector<long long> SegTree;

long long MakeSegTree(int node,int start,int end)
{
    if(start==end) return SegTree[node]=A[start];

    int mid=(start+end)/2;
    long long Left=MakeSegTree(2*node,start,mid);
    long long Right=MakeSegTree(2*node+1,mid+1,end);

    return SegTree[node]=min(Left,Right);
}

long long FindMin(int node,int start,int end,int left,int right)
{
    if(left>end or right<start) return INF;
    if(left<=start and right>=end) return SegTree[node];

    int mid=(start+end)/2;
    long long Left=FindMin(2*node,start,mid,left,right);
    long long Right=FindMin(2*node+1,mid+1,end,left,right);

    return min(Left,Right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M;

    A.resize(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];

    SegTree.resize(4*N);
    MakeSegTree(1,1,N);

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;

        if(a<b) cout<<FindMin(1,1,N,a,b)<<"\n";
        else cout<<FindMin(1,1,N,b,a)<<"\n";
    }

    return 0;
}
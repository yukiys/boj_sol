#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int N,M;
vector<long long> A;
vector<long long> MinTree;
vector<long long> MaxTree;

void MakeSegTree(int node,int start,int end)
{
    if(start==end)
    {
        MinTree[node]=MaxTree[node]=A[start];
        return;
    }

    int mid=(start+end)/2;
    MakeSegTree(2*node,start,mid);
    MakeSegTree(2*node+1,mid+1,end);

    MinTree[node]=min(MinTree[2*node],MinTree[2*node+1]);
    MaxTree[node]=max(MaxTree[2*node],MaxTree[2*node+1]);
    return;
}

long long FindMin(int node,int start,int end,int left,int right)
{
    if(left>end or right<start) return INF;
    if(left<=start and right>=end) return MinTree[node];

    int mid=(start+end)/2;
    long long Left=FindMin(2*node,start,mid,left,right);
    long long Right=FindMin(2*node+1,mid+1,end,left,right);

    return min(Left,Right);
}

long long FindMax(int node,int start,int end,int left,int right)
{
    if(left>end or right<start) return 0;
    if(left<=start and right>=end) return MaxTree[node];

    int mid=(start+end)/2;
    long long Left=FindMax(2*node,start,mid,left,right);
    long long Right=FindMax(2*node+1,mid+1,end,left,right);

    return max(Left,Right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M;

    A.resize(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];

    MinTree.resize(4*N);
    MaxTree.resize(4*N);
    MakeSegTree(1,1,N);

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;

        if(a<b) cout<<FindMin(1,1,N,a,b)<<" "<<FindMax(1,1,N,a,b)<<"\n";
        else cout<<FindMin(1,1,N,b,a)<<" "<<FindMax(1,1,N,b,a)<<"\n";
    }

    return 0;
}
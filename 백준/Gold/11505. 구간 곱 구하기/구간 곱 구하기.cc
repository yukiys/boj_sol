#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

int N,M,K;
vector<long long> A;
vector<long long> SegTree;

long long MakeSegTree(int node,int start,int end)
{
    if(start==end) return SegTree[node]=A[start];

    int mid=(start+end)/2;
    long long Left=MakeSegTree(2*node,start,mid);
    long long Right=MakeSegTree(2*node+1,mid+1,end);

    return SegTree[node]=(Left*Right)%MOD;
}

long long Mul(int node,int start,int end,int left,int right)
{
    if(left>end or right<start) return 1;
    if(left<=start and right>=end) return SegTree[node];

    int mid=(start+end)/2;
    long long Left=Mul(2*node,start,mid,left,right);
    long long Right=Mul(2*node+1,mid+1,end,left,right);

    return (Left*Right)%MOD;
}

void Update(int node,int start,int end,int idx,int value)
{
    if(idx<start or idx>end) return;

    if(start==end)
    {
        SegTree[node]=value;
        return;
    }

    int mid=(start+end)/2;
    Update(2*node,start,mid,idx,value);
    Update(2*node+1,mid+1,end,idx,value);

    SegTree[node]=(SegTree[2*node]*SegTree[2*node+1])%MOD;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M>>K;

    A.resize(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];

    int Height=(int)ceil(log2(N));
    int Size=(1<<(Height+1));
    SegTree.resize(Size+1);
    MakeSegTree(1,1,N);

    for(int i=0;i<M+K;i++)
    {
        int a;
        long long b,c;
        cin>>a>>b>>c;

        if(a==1)
        {
            A[b]=c;
            Update(1,1,N,b,c);
        }
        else
        {
            if(b<c) cout<<Mul(1,1,N,b,c)<<"\n";
            else cout<<Mul(1,1,N,c,b)<<"\n";
        }
    }

    return 0;
}
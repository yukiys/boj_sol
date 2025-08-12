#include <iostream>
#include <vector>
#include <cmath>

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

    return SegTree[node]=Left+Right;
}

long long Sum(int node,int start,int end,int left,int right)
{
    if(left>end or right<start) return 0;
    if(left<=start and right>=end) return SegTree[node];

    int mid=(start+end)/2;
    long long Left=Sum(2*node,start,mid,left,right);
    long long Right=Sum(2*node+1,mid+1,end,left,right);
    
    return Left+Right;
}

void update(int node,int start,int end,int idx,long long diff)
{
    if(idx<start or idx>end) return;
    SegTree[node]+=diff;

    if(start!=end)
    {
        int mid=(start+end)/2;
        update(2*node,start,mid,idx,diff);
        update(2*node+1,mid+1,end,idx,diff);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M>>K;
    
    A.resize(N+1);
    for(int n=1;n<=N;n++) cin>>A[n];

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
            long long diff=c-A[b];
            A[b]=c;
            update(1,1,N,b,diff);
        }
        else
        {
            if(b<c) cout<<Sum(1,1,N,b,c)<<"\n";
            else cout<<Sum(1,1,N,c,b)<<"\n";
        }
    }

    return 0;
}
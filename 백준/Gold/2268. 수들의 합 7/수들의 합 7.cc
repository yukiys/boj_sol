#include <iostream>
#include <vector>

using namespace std;

int N,M;
int A[1000001];
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

void Modify(int node,int start,int end,int idx,long long diff)
{
    if(idx<start or idx>end) return;
    SegTree[node]+=diff;

    if(start!=end)
    {
        int mid=(start+end)/2;
        Modify(2*node,start,mid,idx,diff);
        Modify(2*node+1,mid+1,end,idx,diff);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M;

    SegTree.resize(4*N);
    MakeSegTree(1,1,N);

    for(int i=0;i<M;i++)
    {
        int op,a,b;
        cin>>op>>a>>b;
        
        if(op==0)
        {
            if(a>b) swap(a,b);
            cout<<Sum(1,1,N,a,b)<<"\n";
        }
        else
        {
            long long diff=b-A[a];
            A[a]=b;
            Modify(1,1,N,a,diff);
        }
    }

    return 0;
}
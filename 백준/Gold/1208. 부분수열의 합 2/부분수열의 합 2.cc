#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,S;
int arr[40];
vector<long long> Left,Right;
long long ret;

void input()
{
    cin>>N>>S;
    for(int i=0;i<N;i++) cin>>arr[i];
}

void f(int cur,int end,long long sum,vector<long long>* v)
{
    if(cur==end)
    {
        v->push_back(sum);
        return;
    }

    f(cur+1,end,sum+arr[cur],v);
    f(cur+1,end,sum,v);
}

void solve()
{
    int mid=N/2;

    f(0,mid,0,&Left);
    f(mid,N,0,&Right);

    sort(Right.begin(),Right.end());

    for(int i=0;i<Left.size();i++)
    {
        long long l=Left[i];

        int temp=upper_bound(Right.begin(),Right.end(),S-l)-lower_bound(Right.begin(),Right.end(),S-l);

        ret+=temp;
    }

    if(S==0) ret--;
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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[1000001],parent[1000001];
vector<int> List,Index,ans;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
        parent[i]=-1;
    }
}

void solve()
{
    for(int i=0;i<N;i++)
    {
        if(List.empty() or List.back()<A[i])
        {
            parent[i]=List.empty()?-1:Index.back();
            List.push_back(A[i]);
            Index.push_back(i);
        }
        else
        {
            int pos=lower_bound(List.begin(),List.end(),A[i])-List.begin();
            parent[i]=(pos==0)?-1:Index[pos-1];
            List[pos]=A[i];
            Index[pos]=i;
        }
    }
    
    int idx=Index.back();
    while(idx!=-1)
    {
        ans.push_back(A[idx]);
        idx=parent[idx];
    }
    reverse(ans.begin(),ans.end());
}

void printResult()
{
    cout<<List.size()<<"\n";
    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
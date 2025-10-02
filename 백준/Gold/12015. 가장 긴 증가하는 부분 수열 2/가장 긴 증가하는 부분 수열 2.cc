#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[1000001];
vector<int> List;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
}

void solve()
{
    for(int i=0;i<N;i++)
    {
        if(List.empty() or List.back()<A[i]) List.push_back(A[i]);
        else *lower_bound(List.begin(),List.end(),A[i])=A[i];
    }
}

void printResult()
{
    cout<<List.size()<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
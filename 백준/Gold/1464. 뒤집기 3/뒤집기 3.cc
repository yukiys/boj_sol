#include <iostream>
#include <string>
#include <deque>

using namespace std;

string S;
int N;
deque<char> d;

void input()
{
    cin>>S;
}

void solve()
{
    N=S.size();
    
    d.push_back(S[0]);
    for(int i=1;i<N;i++)
    {
        if(S[i]>d.front()) d.push_back(S[i]);
        else d.push_front(S[i]);
    }
}

void printResult()
{
    for(int i=0;i<N;i++) cout<<d[i];
    cout<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int N,K,k;
stack<int> S,ret;

void input()
{
    cin>>N>>K;
}

void solve()
{
    for(int n=0;n<N;n++)
    {
        char C;
        cin>>C;
        int c=C-'0';

        while(!S.empty() and S.top()<c)
        {
            if(k<K)
            {
                S.pop();
                k++;
            }
            if(k==K) break;
        }
        S.push(c);
    }
    
    while(k<K)
    {
        S.pop();
        k++;
    }
}

void printResult()
{
    while(!S.empty())
    {
        ret.push(S.top());
        S.pop();
    }

    while(!ret.empty())
    {
        cout<<ret.top();
        ret.pop();
    }
    cout<<"\n";
}

int main()
{
    input();
    solve();
    printResult();
}
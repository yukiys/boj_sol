#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> maxQ;
priority_queue<int,vector<int>,greater<int>> minQ;

void solve()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        
        if(minQ.size()==maxQ.size()) maxQ.push(num);
        else minQ.push(num);

        if(!minQ.empty() and minQ.top()<maxQ.top())
        {
            int t1=minQ.top();
            minQ.pop();

            int t2=maxQ.top();
            maxQ.pop();

            minQ.push(t2);
            maxQ.push(t1);
        }

        cout<<maxQ.top()<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
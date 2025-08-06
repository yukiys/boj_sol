#include <iostream>
#include <stack>

using namespace std;

int N;
int num[1000000];
stack<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int n=0;n<N;n++) cin>>num[n];

    for(int n=N-1;n>=0;n--)
    {
        int temp=num[n];

        while(!s.empty() and s.top()<=temp) s.pop();

        if(s.empty()) num[n]=-1;
        else num[n]=s.top();

        s.push(temp);
    }

    for(int n=0;n<N;n++) cout<<num[n]<<" ";

    cout<<"\n";

    return 0;
}
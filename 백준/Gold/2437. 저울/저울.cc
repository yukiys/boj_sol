#include <iostream>
#include <algorithm>

using namespace std;

int N,ret;
int weight[1000];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>weight[i];
}

void solve()
{
    sort(weight,weight+N);

    ret=1;

    for(int i=0;i<N;i++)
    {
        if(ret>=weight[i]) ret+=weight[i];
        else break;
    }
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
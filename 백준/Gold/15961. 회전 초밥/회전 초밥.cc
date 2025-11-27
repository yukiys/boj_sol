#include <iostream>

using namespace std;

int N,d,k,c,ret;
int sushi[3000000];
int eat[3000001];

void input()
{
    cin>>N>>d>>k>>c;
    for(int i=0;i<N;i++)
        cin>>sushi[i];
}

void solve()
{
    int cnt=0,temp;
    for(int i=0;i<k;i++)
    {
        eat[sushi[i]]++;
        if(eat[sushi[i]]==1) cnt++;
    }

    temp=cnt;
    if(eat[c]==0) temp++;
    ret=temp;

    for(int n=1;n<N;n++)
    {
        eat[sushi[n-1]]--;
        if(eat[sushi[n-1]]==0) cnt--;

        eat[sushi[(n+k-1)%N]]++;
        if(eat[sushi[(n+k-1)%N]]==1) cnt++;

        temp=cnt;
        if(eat[c]==0) temp++;
        ret=max(ret,temp);
    }   
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}
#include <iostream>
#include <bitset>

using namespace std;

bitset<(1<<25)> visited;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x;
    while(cin>>x)
    {
        if(!visited[x])
        {
            visited[x]=true;
            cout<<x<<" ";
        }
    }
    cout<<"\n";

    return 0;
}
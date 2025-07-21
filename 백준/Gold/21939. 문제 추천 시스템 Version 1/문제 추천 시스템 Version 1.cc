#include <iostream>
#include <set>
#include <map>

using namespace std;

int N,M;
multiset<pair<int,int>> ms;
map<int,int> Map;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int p,l;
    for(int i=0;i<N;i++)
    {
        cin>>p>>l;
        ms.insert({l,p});
        Map[p]=l;
    }

    cin>>M;
    for(int i=0;i<M;i++)
    {
        string op;
        cin>>op;

        if(op[0]=='a')
        {
            int p,l;
            cin>>p>>l;
            ms.insert({l,p});
            Map[p]=l;
        }
        else if(op[0]=='r')
        {
            int x;
            cin>>x;
            if(x==1) cout<<ms.rbegin()->second<<"\n";
            else cout<<ms.begin()->second<<"\n";
        }
        else
        {
            int p;
            cin>>p;
            ms.erase(ms.find({Map[p],p}));
        }
    }

    return 0;
}
#include <iostream>
#include <set>
#include <map>

using namespace std;

int N,M;
map<int,multiset<pair<int,int>>> GLP;
multiset<pair<int,int>> LP;
map<int,pair<int,int>> PLG;

void operation(string op)
{
    if(op=="add")
    {
        int p,l,g;
        cin>>p>>l>>g;
        GLP[g].insert({l,p});
        LP.insert({l,p});
        PLG[p]={l,g};
    }
    else if(op=="recommend")
    {
        int g,x;
        cin>>g>>x;
        if(x==1) cout<<GLP[g].rbegin()->second<<"\n";
        else cout<<GLP[g].begin()->second<<"\n";
    }
    else if(op=="recommend2")
    {
        int x;
        cin>>x;
        if(x==1) cout<<LP.rbegin()->second<<"\n";
        else cout<<LP.begin()->second<<"\n";
    }
    else if(op=="recommend3")
    {
        int x,l;
        cin>>x>>l;
        if(x==1)
        {
            auto iter=LP.lower_bound({l,0});
            if(iter!=LP.end()) cout<<iter->second<<"\n";
            else cout<<-1<<"\n";
        }
        else
        {
            auto iter=LP.upper_bound({l,0});
            if(iter!=LP.begin()) cout<<(--iter)->second<<"\n";
            else cout<<-1<<"\n";
        }
    }
    else
    {
        int p;
        cin>>p;
        int l=PLG[p].first;
        int g=PLG[p].second;

        GLP[g].erase(GLP[g].find({l,p}));
        LP.erase({LP.find({l,p})});
        PLG.erase(p);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int p,l,g;
    for(int i=0;i<N;i++)
    {
        cin>>p>>l>>g;
        GLP[g].insert({l,p});
        LP.insert({l,p});
        PLG[p]={l,g};
    }

    cin>>M;
    string op;
    for(int i=0;i<M;i++)
    {
        cin>>op;
        operation(op);
    }

    return 0;
}
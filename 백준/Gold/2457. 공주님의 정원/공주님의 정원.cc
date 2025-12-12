#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,ret;
vector<pair<int,int>> days;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        days.push_back({100*a+b,100*c+d});
    }
}


bool solve()
{
    sort(days.begin(),days.end());

    int cur=301;
    for(int i=0;i<days.size();i++)
    {
        int start=days[i].first;
        int end=days[i].second;

        if(start>cur) return false;
        ret++;

        int M=days[i].second,next=i+1;
        for(int j=i+1;j<days.size();j++)
        {
            if(days[j].first>cur) break;
            
            if(days[j].second>M)
            {
                M=days[j].second;
                next=j;
            }
        }
        cur=M;
        i=next-1;

        if(cur>1130) return true;
    }

    return false;
}

void printResult(bool check)
{
    if(check) cout<<ret<<"\n";
    else cout<<0<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    bool check=solve();
    printResult(check);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N,ret;
int weight[26];
vector<int> V;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string str;
        cin>>str;
        
        int w=1;
        for(int j=str.size()-1;j>=0;j--)
        {
            weight[str[j]-'A']+=w;
            w*=10;
        }
    }
}

void solve()
{
    for(int i=0;i<26;i++)
        if(weight[i]>0)
            V.push_back(weight[i]);
    
    sort(V.rbegin(),V.rend());

    int n=9;
    for(int i=0;i<V.size();i++)
    {
        ret+=V[i]*n;
        n--;
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
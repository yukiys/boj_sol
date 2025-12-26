#include <iostream>
#include <vector>

using namespace std;

int H,W,ret;
int block[500];
vector<int> V;

void init()
{
    cin>>H>>W;
    for(int i=0;i<W;i++) cin>>block[i];
}

void solve()
{
    for(int i=0;i<W;i++)
    {
        while(!V.empty() and block[i]>block[V.back()])
        {
            int bottom=V.back();
            V.pop_back();
            if(V.empty()) break;

            int left=V.back();
            int w=i-left-1;
            int h=min(block[left],block[i])-block[bottom];
            ret+=(w*h);
        }
        V.push_back(i);
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}
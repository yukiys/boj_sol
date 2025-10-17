#include <iostream>
#include <string>

using namespace std;

string str,ans;

void input()
{
    cin>>str;
}

void solve()
{
    for(char c:str)
    {
        ans.push_back(c);

        if(ans.size()>=4 and c=='P')
        {
            if(ans[ans.size()-4]!='P') continue;
            if(ans[ans.size()-3]!='P') continue;
            if(ans[ans.size()-2]!='A') continue;

            for(int i=0;i<3;i++) ans.pop_back();
        }
    }
}

void printResult()
{
    if(ans.compare("P")==0) cout<<"PPAP"<<"\n";
    else cout<<"NP"<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
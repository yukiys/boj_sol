#include <iostream>
#include <string>

using namespace std;

string str,bomb,ans;
int s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>str>>bomb;
    s=bomb.size();

    for(char c:str)
    {
        ans.push_back(c);

        if(ans.size()>=s and c==bomb[s-1])
        {
            bool check=true;
            for(int i=0;i<s;i++)
            {
                if(ans[ans.size()-s+i]!=bomb[i])
                {
                    check=false;
                    break;
                }
            }
            if(check) ans.resize(ans.size()-s);
        }
    }

    cout<<((ans.empty())?"FRULA":ans)<<"\n";

    return 0;
}
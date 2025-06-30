#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string S,T;
    cin>>S>>T;

    int s=S.size();
    int t=T.size();
    while(s<t)
    {
        if(T.back()=='B')
        {
            t--;
            T.pop_back();
            reverse(T.begin(),T.end());
        }
        else
        {
            t--;
            T.pop_back();
        }
    }

    if(S==T) cout<<"1\n";
    else cout<<"0\n";

    return 0;
}
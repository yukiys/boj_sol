#include <iostream>

using namespace std;

int T;
long long N;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;

        if(N%10==0) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}
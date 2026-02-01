#include <iostream>

using namespace std;

long long N;
int ret;

void init()
{
    cin>>N;
}

void solve()
{
    if(N%5==0 or N%5==2) ret=1;
    else ret=0;
}

void printRet()
{
    if(ret==0) cout<<"SK"<<"\n";
    else cout<<"CY"<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}
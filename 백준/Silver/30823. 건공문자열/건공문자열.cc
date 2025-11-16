#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N,K;
string str,ret;

void input()
{
    cin>>N>>K;
    cin>>str;
}

void solve()
{
    string temp1=str.substr(K-1);
    string temp2=str.substr(0,K-1);
    if((N-K)%2==0) reverse(temp2.begin(),temp2.end());

    ret=temp1+temp2;
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
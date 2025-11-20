#include <iostream>
#include <string>
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull k;
int ret;

void input()
{
    cin>>k;
}

ull findLength()
{
    for(ull L=1;;L++)
    {
        ull h=(L+1)/2;

        ull temp=9;
        for(ull i=1;i<h;i++) temp*=10;

        __int128_t block=(__int128_t)temp*L;

        if(k>block) k-=block;
        else return L;
    }
}

void solve()
{
    ull L=findLength();

    k--;
    ull idx=k/L;
    ull pos=k%L;

    ull h=(L+1)/2;
    ull temp=1;
    for(ull i=1;i<h;i++) temp*=10;

    temp+=idx;
    string s=to_string(temp);
    string palindrome=s;
    if(L%2==0)
    {
        string rev=s;
        reverse(rev.begin(),rev.end());
        palindrome+=rev;
    }
    else
    {
        string rev=s.substr(0,s.size()-1);
        reverse(rev.begin(),rev.end());
        palindrome+=rev;
    }

    ret=palindrome[pos]-'0';
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
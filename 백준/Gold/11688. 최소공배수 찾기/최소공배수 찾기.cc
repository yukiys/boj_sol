#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a,b,c=-1,L;
vector<long long> V;

long long gcd(long long a,long long b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

void input()
{
    cin>>a>>b>>L;
    a=a*b/gcd(a,b);
}

void solve()
{
    if(L%a!=0) return;

    for(long long i=1;i*i<=L;i++)
    {
        if(L%i==0)
        {
            V.push_back(i);
            if(i*i!=L) V.push_back(L/i);
        }
    }
    sort(V.begin(),V.end());

    for(int i=0;i<V.size();i++)
    {
        if(a*V[i]==gcd(a,V[i])*L)
        {
            c=V[i];
            return;
        }
    }
}

void printResult()
{
    cout<<c<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
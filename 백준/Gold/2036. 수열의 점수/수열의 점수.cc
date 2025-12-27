#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,p,one,m,z;
long long ret;
vector<int> A;

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        if(a==0) z++;
        else if(a==1) one++;
        else
        {
            if(a<0) m++;
            else p++;
            A.push_back(a);
        }
    }
}

void solve()
{
    ret=one;

    sort(A.begin(),A.end());
    while(p>1)
    {
        long long temp=A.back();
        A.pop_back();
        temp*=1LL*A.back();
        A.pop_back();
        ret+=temp;
        p-=2;
    }
    if(p==1)
    {
        ret+=A.back();
        A.pop_back();
    }

    sort(A.rbegin(),A.rend());
    while(m>1)
    {
        long long temp=A.back();
        A.pop_back();
        temp*=1LL*A.back();
        A.pop_back();
        ret+=temp;
        m-=2;
    }
    if(m==1 and z==0)
        ret+=A.back();
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
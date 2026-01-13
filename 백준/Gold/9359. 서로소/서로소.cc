#include <iostream>
#include <vector>

using namespace std;

int T;
long long A,B,N,ret;
vector<int> factors;

void factorize(long long num)
{
    for(int p=2;p*p<=num;p++)
    {
        if(num%p==0)
        {
            factors.push_back(p);
            while(num%p==0)
                num/=p;
        }
    }
    if(num>1) factors.push_back(num);
}

void init()
{
    cin>>A>>B>>N;
    ret=B-A+1;
    factors.clear();
}

void dfs(int idx,long long prod,int depth)
{
    for(int i=idx;i<factors.size();i++)
    {
        int p=factors[i];
        if(prod>B/p) break;

        long long nprod=prod*p;
        long long add=B/nprod-(A-1)/nprod;
        
        if(depth%2==0) ret-=add;
        else ret+=add;

        dfs(i+1,nprod,depth+1);
    }
}

void solve()
{
    factorize(N);

    dfs(0,1,0);
}

void printRet(int t)
{
    cout<<"Case #"<<t<<": "<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        init();
        solve();
        printRet(t);
    }
}
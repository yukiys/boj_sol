#include <iostream>
#include <vector>

using namespace std;

int T;
long long k,x;
vector<long long> fibo;

void input()
{
    cin>>k>>x;
}

void solve()
{
    if(k==1)
    {
        for(int i=0;i<fibo.size();i++)
        {
            if(x==fibo[i])
            {
                cout<<"YES"<<"\n";
                return;
            }
        }
        cout<<"NO"<<"\n";
    }
    else if(k==2)
    {
        for(int i=0;i<fibo.size();i++)
        {
            x-=fibo[i];
            for(int j=0;j<fibo.size();j++)
            {
                if(x==fibo[j])
                {
                    cout<<"YES"<<"\n";
                    return;
                }
            }
            x+=fibo[i];
        }
        cout<<"NO"<<"\n";
    }
    else
    {
        for(int i=0;i<fibo.size();i++)
        {
            x-=fibo[i];
            for(int j=0;j<fibo.size();j++)
            {
                x-=fibo[j];
                for(int k=0;k<fibo.size();k++)
                {
                    if(x==fibo[k])
                    {
                        cout<<"YES"<<"\n";
                        return;
                    }
                }
                x+=fibo[j];
            }
            x+=fibo[i];
        }
        cout<<"NO"<<"\n";
    }
}

int main()
{
    long long a=1,b=1,c=a+b;
    fibo.push_back(1);
    fibo.push_back(1);
    while((c=a+b)<1e16)
    {
        fibo.push_back(c);
        a=b;
        b=c;
    }

    cin>>T;
    while(T--)
    {
        input();
        solve();
    }

    return 0;
}
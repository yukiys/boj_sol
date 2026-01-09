#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N,ret=2e9;
int H[600];

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>H[i];
}

void solve()
{
    sort(H,H+N);

    for(int i=0;i+3<N;i++)
    {
        for(int j=i+3;j<N;j++)
        {
            int Anna=H[i]+H[j];

            int l=i+1,r=j-1;
            while(l<r)
            {
                int Elsa=H[l]+H[r];
                ret=min(ret,abs(Anna-Elsa));

                if(Anna>Elsa)
                    l++;
                else if(Anna<Elsa)
                    r--;
                else
                    return;
            }
        }
    }
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
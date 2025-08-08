#include <iostream>

using namespace std;

int N,S;
int A[100000];
int ret=999999,l=0,r=0;
long long sum;

int main()
{
    cin>>N>>S;
    for(int i=0;i<N;i++) cin>>A[i];

    sum=0;
    while(1)
    {
        if(sum>=S)
        {
            ret=min(ret,r-l);
            sum-=A[l++];
        }
        else
        {
            if(r==N) break;
            sum+=A[r++];
        }
    }

    if(ret==999999) cout<<0<<"\n";
    else cout<<ret<<"\n";

    return 0;
}
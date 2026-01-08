#include <iostream>

using namespace std;

int N,ret=100001;
int A[100000],B[100000];

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>B[i];
}

void solve()
{
    if(N==1)
    {
        ret=0;
        return;
    }

    for(int d0=-1;d0<=1;d0++)
    {
        for(int d1=-1;d1<=1;d1++)
        {
            int cnt=0;
            if(d0!=0) cnt++;
            if(d1!=0) cnt++;

            for(int i=0;i<N;i++)
                A[i]=B[i];
            A[0]+=d0;
            A[1]+=d1;
            int diff=A[1]-A[0];
            bool check=true;

            for(int i=2;i<N;i++)
            {
                if(A[i]-A[i-1]==diff+1)
                {
                    A[i]-=1;
                    cnt++;
                }
                else if(A[i]-A[i-1]==diff-1)
                {
                    A[i]+=1;
                    cnt++;
                }
                else if(A[i]-A[i-1]!=diff)
                {
                    check=false;
                    break;
                }
            }
            
            if(check) ret=min(ret,cnt);
        }
    }
}

void printRet()
{
    if(ret==100001) cout<<-1<<"\n";
    else cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}
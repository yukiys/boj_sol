#include <iostream>

using namespace std;

int N;

bool isPrime(int num)
{
    if(num==1) return false;

    for(int i=2;i*i<=num;i++)
        if(num%i==0)
            return false;

    return true;
}

void backTracking(int depth,int num)
{
    if(depth==N)
    {
        cout<<num<<"\n";
        return;
    }

    int start=0;
    if(depth==0) start=1;
    for(int i=start;i<10;i++)
    {
        int next=num*10+i;
        if(isPrime(next)) backTracking(depth+1,next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    
    cin>>N;

    backTracking(0,0);

    return 0;
}
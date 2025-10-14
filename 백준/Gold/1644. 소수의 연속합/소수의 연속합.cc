#include <iostream>
#include <vector>

using namespace std;

int N,Size,ret;
vector<int> V;

void input()
{
    cin>>N;
}

bool isPrime(int num)
{
    for(int div=2;div*div<=num;div++)
        if(num%div==0)
            return false;

    return true;
}

void solve()
{
    for(int n=2;n<=N;n++)
        if(isPrime(n))
            V.push_back(n);
    
    Size=V.size();
    if(Size==0) return;

    int left=0,right=0,sum=V[0];
    while(left<Size and right<Size)
    {
        if(sum<N) sum+=V[++right];
        else if(sum>N) sum-=V[left++];
        else
        {
            ret++;
            sum-=V[left++];
        }
    }
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
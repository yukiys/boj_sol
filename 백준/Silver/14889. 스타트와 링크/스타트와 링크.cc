#include <iostream>
#include <algorithm>

using namespace std;

int N,area[20][20],m=123456789;   
bool idx[20];

void dfs(int depth,int num)
{
    if(depth==N/2)
    {
        int sum1=0,sum2=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(idx[i] and idx[j]) sum1+=area[i][j];
                else if(!idx[i] and !idx[j]) sum2+=area[i][j];
            }
        }

        if(abs(sum2-sum1)<m) m=abs(sum2-sum1);
    }

    for(int i=num;i<N;i++)
    {
        idx[i]=true;
        dfs(depth+1,i+1);
        idx[i]=false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>area[i][j];

    dfs(0,0);
    cout<<m<<"\n";
    return 0;
}
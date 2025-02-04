#include <iostream>
#include <algorithm>

using namespace std;

long long N,sum;
int dice[6],M;

int main()
{
    cin>>N;
    for(int i=0;i<6;i++)
    {
        cin>>dice[i];
        M=max(M,dice[i]);
        sum+=dice[i];
    }

    if(N==1) cout<<sum-M<<"\n";
    else
    {
        dice[0]=min(dice[0],dice[5]);
        dice[1]=min(dice[1],dice[4]);
        dice[2]=min(dice[2],dice[3]);
        sort(dice,dice+3);

        int sum1=dice[0];
        int sum2=sum1+dice[1];
        int sum3=sum2+dice[2];

        cout<<4*sum3+(8*N-12)*sum2+(N-2)*(5*N-6)*sum1<<"\n";
    }

    return 0;
}
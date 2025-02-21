#include <iostream>

using namespace std;

int N;
int input[3];
int m[3];
int M[3];

int main()
{
    cin>>N;
    for(int i=0;i<3;i++)
    {
        cin>>input[i];
        m[i]=M[i]=input[i];
    }

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<3;j++)
            cin>>input[j];

        int pm0=m[0],pm1=m[1],pm2=m[2];
        m[0]=input[0]+min(pm0,pm1);
        m[1]=input[1]+min(min(pm0,pm1),pm2);
        m[2]=input[2]+min(pm1,pm2);

        int pM0=M[0],pM1=M[1],pM2=M[2];
        M[0]=input[0]+max(pM0,pM1);
        M[1]=input[1]+max(max(pM0,pM1),pM2);
        M[2]=input[2]+max(pM1,pM2);
    }

    int Max=max(max(M[0],M[1]),M[2]);
    int Min=min(min(m[0],m[1]),m[2]);

    cout<<Max<<" "<<Min<<"\n";

    return 0;
}
#include <iostream>

#define MOD 1000000

using namespace std;

long long N;
long long matrix[2][2]={{1,1},{1,0}};
long long ret[2][2]={{1,0},{0,1}};

void MatrixMul(long long a[2][2],long long b[2][2])
{
    long long c[2][2];

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++) c[i][j]+=a[i][k]*b[k][j];
            c[i][j]%=MOD;
        }
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=c[i][j];
}

int main()
{
    cin>>N;

    while(N>0)
    {
        if(N%2==1) MatrixMul(ret,matrix);
        MatrixMul(matrix,matrix);
        N/=2;
    }

    cout<<ret[0][1]<<"\n";

    return 0;
}
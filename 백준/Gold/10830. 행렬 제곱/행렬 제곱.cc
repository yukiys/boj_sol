#include <iostream>

#define MOD 1000

using namespace std;

int N;
long long B;
int matrix[5][5];
int ret[5][5];

void MatrixMul(int a[5][5],int b[5][5])
{
    int c[5][5];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            c[i][j]=0;
            for(int k=0;k<N;k++) c[i][j]+=a[i][k]*b[k][j];
            c[i][j]%=MOD;
        }
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]=c[i][j];
}

void input()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++) cin>>matrix[i][j];
        ret[i][i]=1;
    }
}

void solve()
{
    while(B>0)
    {
        if(B%2==1) MatrixMul(ret,matrix);
        MatrixMul(matrix,matrix);
        B/=2;
    }
}

void printAnswer()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++) cout<<ret[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    cin>>N>>B;

    input();
    solve();
    printAnswer();

    return 0;
}
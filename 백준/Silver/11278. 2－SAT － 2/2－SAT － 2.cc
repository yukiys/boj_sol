#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N,M; cin>>N>>M;
    int A[2][100];
    bool B[21];
    for(int i=0;i<M;i++) cin>>A[0][i]>>A[1][i];

    for(int i=0;i<pow(2,N);i++)
    {
        int div=pow(2,N-1);
        int tmp=i;
        for(int j=N;j>=1;j--)
        {
            if(tmp>=div)
            {
                tmp-=div;
                B[j]=true;
            }
            else B[j]=false;
            div/=2;
        }

        for(int j=0;j<M;j++)   
        {
            int a=A[0][j],b=A[1][j];
            bool ab=B[abs(a)],bb=B[abs(b)];
            if(a<0) ab=!ab;
            if(b<0) bb=!bb;

            if(!ab and !bb) break;
            if(j==M-1)
            {
                cout<<"1\n";
                for(int n=1;n<=N;n++) cout<<B[n]<<" ";
                cout<<"\n";
                return 0;
            }
        }
    }

    cout<<"0\n";
    return 0;
}
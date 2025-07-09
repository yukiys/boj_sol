#include <iostream>

using namespace std;

string A,B;
int LCS[4001][4001];
int ret;

int main()
{
    cin>>A>>B;
    A="0"+A;
    B="0"+B;

    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<B.size();j++)
        {
            if(i==0 or j==0) LCS[i][j]=0;
            else if(A[i]==B[j]) LCS[i][j]=LCS[i-1][j-1]+1;
            else LCS[i][j]=0;

            ret=max(ret,LCS[i][j]);
        }
    }

    cout<<ret<<"\n";

    return 0;
}
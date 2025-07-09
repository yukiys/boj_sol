#include <iostream>

using namespace std;

string A,B,C;
int LCS[101][101][101];

int main()
{
    cin>>A>>B>>C;
    A="0"+A;
    B="0"+B;
    C="0"+C;

    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<B.size();j++)
        {
            for(int k=0;k<C.size();k++)
            {
                if(i==0 or j==0 or k==0) LCS[i][j][k]=0;
                else if(A[i]==B[j] and B[j]==C[k]) LCS[i][j][k]=LCS[i-1][j-1][k-1]+1;
                else LCS[i][j][k]=max(max(LCS[i-1][j][k],LCS[i][j-1][k]),LCS[i][j][k-1]);
            }
        }
    }

    cout<<LCS[A.size()-1][B.size()-1][C.size()-1]<<"\n";

    return 0;
}
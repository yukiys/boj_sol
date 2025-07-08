#include <iostream>

using namespace std;

string A,B;
int LCS[1001][1001];

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
            else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }

    cout<<LCS[A.size()-1][B.size()-1]<<"\n";

    return 0;
}
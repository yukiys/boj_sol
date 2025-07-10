#include <iostream>
#include <algorithm>

using namespace std;

string A,B,C;
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

    int i=A.size()-1,j=B.size()-1;
    while(LCS[i][j]!=0)
    {
        if(LCS[i][j]==LCS[i-1][j])
        {
            i--;
            continue;
        }
        if(LCS[i][j]==LCS[i][j-1])
        {
            j--;
            continue;
        }
        C.push_back(A[i]);
        i--;
        j--;
    }
    reverse(C.begin(),C.end());

    cout<<C<<"\n";

    return 0;
}
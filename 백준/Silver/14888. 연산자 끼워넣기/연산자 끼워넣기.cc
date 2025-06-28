#include <iostream>

using namespace std;

int N;
int num[11];
int op[4];
int m=1000000001, M=-1000000001;

void backtracking(int result,int depth)
{
    if(depth==N)
    {
        if(result>M) M=result;
        if(result<m) m=result;
        
        return;
    }

    for(int i=0;i<4;i++)
    {
        if(op[i]>0)
        {
            op[i]--;
            if(i==0) backtracking(result+num[depth],depth+1);
            else if(i==1) backtracking(result-num[depth],depth+1);
            else if(i==2) backtracking(result*num[depth],depth+1);
            else backtracking(result/num[depth],depth+1);
            op[i]++;
        }
    }

    return;
}

int main()
{
    cin>>N;
    for(int n=0;n<N;n++) cin>>num[n];

    for(int i=0;i<4;i++) cin>>op[i];

    backtracking(num[0],1);

    cout<<M<<"\n"<<m<<"\n";

    return 0;
}
#include <iostream>

using namespace std;

int N;
int buildings[50];
int ret;

void CountNum(int n)
{
    double left=1000000000,right=-1000000000;
    int lC=0,rC=0;

    for(int i=n-1;i>=0;i--)
    {
        double temp=(double)(buildings[n]-buildings[i])/(n-i);
        if(temp<left)
        {
            left=temp;
            lC++;
        }
    }
    for(int i=n+1;i<N;i++)
    {
        double temp=(double)(buildings[n]-buildings[i])/(n-i);
        if(temp>right)
        {
            right=temp;
            rC++;
        }
    }

    ret=max(ret,lC+rC);
}

int main()
{
    cin>>N;
    for(int n=0;n<N;n++) cin>>buildings[n];

    for(int n=0;n<N;n++) CountNum(n);

    cout<<ret<<"\n";

    return 0;
}
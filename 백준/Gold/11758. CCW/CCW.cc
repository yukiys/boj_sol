#include <iostream>

using namespace std;

int x[3],y[3];

int main()
{
    for(int i=0;i<3;i++) cin>>x[i]>>y[i];

    int cross=(x[1]-x[0])*(y[2]-y[1])-(x[2]-x[1])*(y[1]-y[0]);

    if(cross>0) cout<<1<<"\n";
    else if(cross<0) cout<<-1<<"\n";
    else cout<<0<<"\n";

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

double X,Y,D,T,ret;

int main()
{
    cin>>X>>Y>>D>>T;

    double d=sqrt(X*X+Y*Y);
    while(1)
    {
        double temp=abs(d-D);

        double Case=min(T+temp,d);
        if(2*D>d) Case=min(Case,2*T);

        if(Case==T+temp)
        {
            d=temp;
            ret+=T;
        }
        else if(Case==d)
        {
            ret+=d;
            break;
        }
        else
        {
            ret+=2*T;
            break;
        }
    }

    cout<<fixed;
    cout.precision(9);
    cout<<ret<<"\n";

    return 0;
}
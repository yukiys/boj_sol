#include <iostream>

using namespace std;

int xs,ys;
int xe,ye,dx,dy;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int calc()
{
    return (xe-xs)*(xe-xs)+(ye-ys)*(ye-ys);
}

int main()
{
    cin>>xs>>ys>>xe>>ye>>dx>>dy;

    if(dx!=0 and dy!=0)
    {
        int GCD=gcd(dx,dy);
        dx/=GCD;
        dy/=GCD;
    }
    else
    {
        if(dx==0) dy=1;
        else if(dy==0) dx=1;
        else
        {
            cout<<xe<<" "<<ye<<"\n";
            return 0;
        }
    }

    int dist=calc();
    while(1)
    {
        xe+=dx;
        ye+=dy;
        if(dist<calc()) break;
        dist=calc();
    }
    cout<<xe-dx<<" "<<ye-dy<<"\n";

    return 0;
}
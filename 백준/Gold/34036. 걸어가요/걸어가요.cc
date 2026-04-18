#include <iostream>

using namespace std;

int N;
long long X[10],S[10];
long long x,s;

struct ExtendedGCDResult
{
    long long gcd;
    long long x;
    long long y;
};

ExtendedGCDResult extGCD(long long, long long);
long long GCD(long long, long long);
bool mergeCRT(long long, long long, long long, long long, long long &, long long &);
void init();
void solve();
void printAns();

int main()
{
    init();
    solve();
    printAns();
}

ExtendedGCDResult extGCD(long long a,long long b)
{
    if(b == 0)
        return {a, 1, 0};

    auto prev = extGCD(b, a % b);
    return {prev.gcd, prev.y, prev.x - (a / b) * prev.y};
}

long long GCD(long long a, long long b)
{
    while(b != 0)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool mergeCRT(long long x1, long long s1, long long x2, long long s2, long long &outX, long long &outS)
{
    long long g = GCD(s1, s2);
    long long diff = x2 - x1;

    if(diff % g != 0)
        return false;

    long long a = s1 / g;
    long long b = s2 / g;

    auto eg = extGCD(a, b);
    long long aInv = (eg.x % b + b) % b;

    long long t=((diff / g) % b + b) % b;

    t = (t * aInv) % b;

    long long lcm = a * s2;

    outX = ((x1 + s1 * t) % lcm + lcm) % lcm;
    outS = lcm;
    return true;
}

void init()
{
    cin >> N;
    for(int i=0; i < N; i++)
        cin >> X[i] >> S[i];
}

void solve()
{
    x = X[0], s = S[0];
    x = (x % s + s) % s;
    long long maxX = X[0];

    for(int i=1; i < N; i++)
    {
        maxX = max(maxX, X[i]);
        
        long long nx, ns;
        if(!mergeCRT(x ,s , X[i], S[i], nx, ns))
        {
            x = -1;
            break;
        }
        x = nx;
        s = ns;
    }

    if(x != -1 and x < maxX)
    {
        long long k = (maxX - x + s - 1) / s;
        x += k * s;
    }
}

void printAns()
{
    cout << x << "\n";
}
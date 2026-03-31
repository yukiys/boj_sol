#include <iostream>
#include <vector>

using namespace std;

const int MAX = 32;

int N, XOR;
int P[100001], maxP;
vector<int> fibo;
int grundy[3000001];

void init();
void solve();
void printAns();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printAns();
}

void init()
{
    cin >> N;
    
    fibo.push_back(1);
    fibo.push_back(1);
    for(int i = 2; i <= MAX; i++)
        fibo.push_back(fibo[i-1] + fibo[i-2]);

    for(int i = 0; i < N; i++)
    {
        cin >> P[i];
        maxP = max(maxP, P[i]);
    }
}

void solve()
{
    for(int x = 1; x <= maxP; x++)
    {
        bool seen[MAX + 1] = {};
        for(int f : fibo)
            if(f <= x)
                seen[grundy[x-f]] = true;

        int mex = 0;
        while(seen[mex])
            mex++;

        grundy[x] = mex;
    }

    for(int i = 0; i < N; i++)
        XOR ^= grundy[P[i]];
}

void printAns()
{
    if(XOR == 0)
        cout << "cubelover" << "\n";
    else
        cout << "koosaga" << "\n";
}
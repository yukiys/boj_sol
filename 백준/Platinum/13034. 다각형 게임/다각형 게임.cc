#include <iostream>
#include <vector>

using namespace std;

int N;
int grundy[1001];

int main()
{
    cin >> N;
    grundy[2] = 1;
    for(int n = 3; n <= N; n++)
    {
        vector<bool> seen(1001, false);

        for(int k = 0; k <= n - 2; k++)
            seen[grundy[k] ^ grundy[n - 2 - k]] = true;

        int mex = 0;
        while(seen[mex])
            mex++;

        grundy[n] = mex;
    }

    if(grundy[N] != 0)
        cout << "1" << "\n";
    else
        cout << "2" << "\n";
}
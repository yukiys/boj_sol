#include <iostream>

using namespace std;

int N, XOR, ans;
int P[1000];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> P[i];
        XOR ^= P[i];
    }

    for(int i = 0; i < N; i++)
        if(P[i] > (XOR ^ P[i]))
            ans++;

    cout << ans << "\n";
}
#include <iostream>

using namespace std;

int T;
int N, M;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
        }

        cout << N - 1 << "\n";
    }
}
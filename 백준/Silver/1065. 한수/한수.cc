#include <iostream>

using namespace std;

int N, ans;

int main()
{
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        if(i < 100)
            ans++;
        else
        {
            int a = i % 10;
            int b = (i / 10) % 10;
            int c = i / 100;

            if(a - b == b - c)
                ans++;
        }
    }

    cout << ans << "\n";
}
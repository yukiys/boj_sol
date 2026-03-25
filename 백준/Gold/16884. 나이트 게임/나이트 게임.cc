#include <iostream>

using namespace std;

int T, N;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;

        if(N % 2 == 0)
            cout << "cubelover" << "\n";
        else
            cout << "koosaga" << "\n";
    }
}
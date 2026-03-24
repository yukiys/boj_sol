#include <iostream>

using namespace std;

int N, XOR;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        XOR ^= p;
    }

    if(XOR == 0)
        cout << "cubelover" << "\n";
    else
        cout << "koosaga" << "\n";
}
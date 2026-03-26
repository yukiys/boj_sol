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
        if(p % 2 ==0)
            XOR ^= (p - 2) / 2;
        else
            XOR ^= (p + 1) / 2;
    }

    if(XOR == 0)
        cout << "cubelover" << "\n";
    else
        cout << "koosaga" << "\n";
}
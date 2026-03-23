#include <iostream>

using namespace std;

int N, XOR;
bool allOne = true;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        XOR ^= p;
        if(p != 1)
            allOne = false;
    }

    if(allOne)
    {
        if(N % 2 ==0)
            cout << "koosaga" << "\n";
        else
            cout << "cubelover" << "\n";
    }
    else
    {
        if(XOR == 0)
            cout << "cubelover" << "\n";
        else
            cout << "koosaga" << "\n";
    }
}
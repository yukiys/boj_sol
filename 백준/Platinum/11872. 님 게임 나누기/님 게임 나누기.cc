#include <iostream>
#include <vector>

using namespace std;

int N, XOR;

int grundy(int);

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int p;
        cin >> p;

        XOR ^= (grundy(p));
    }

    if(XOR == 0)
        cout << "cubelover" << "\n";
    else
        cout << "koosaga" << "\n";
}

int grundy(int x)
{
    if(x % 4 == 3)
        return x + 1;
    else if(x % 4 == 0)
        return x - 1;
    else
        return x;
}
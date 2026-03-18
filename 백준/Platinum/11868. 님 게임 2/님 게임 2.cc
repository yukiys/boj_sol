#include <iostream>

using namespace std;

int N, Pi;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int nextP;
        cin >> nextP;
        Pi ^= nextP;
    }

    if(Pi == 0)
        cout << "cubelover" << "\n";
    else
        cout << "koosaga" << "\n";
}
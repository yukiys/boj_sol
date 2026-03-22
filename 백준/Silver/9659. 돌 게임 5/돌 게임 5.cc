#include <iostream>

using namespace std;

long long N;

int main()
{
    cin >> N;

    if(N % 2 == 1)
        cout << "SK" << "\n";
    else
        cout << "CY" << "\n";
}
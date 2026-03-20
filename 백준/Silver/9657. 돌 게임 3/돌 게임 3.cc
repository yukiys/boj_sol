#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;

    if(N % 7 == 2 or N % 7 == 0)
        cout << "CY" << "\n";
    else
        cout << "SK" << "\n";
}
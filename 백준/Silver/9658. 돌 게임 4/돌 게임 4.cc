#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;

    if(N % 7 == 1 or N % 7 == 3)
        cout << "CY" << "\n";
    else
        cout << "SK" << "\n";
}
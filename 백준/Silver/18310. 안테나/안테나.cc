#include <iostream>
#include <algorithm>

using namespace std;

int N;
int houses[200000];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> houses[i];
    
    sort(houses, houses + N);

    cout << houses[(N - 1) / 2] << "\n";
}
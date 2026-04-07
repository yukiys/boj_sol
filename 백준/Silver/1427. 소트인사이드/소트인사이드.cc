#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    string str;
    cin >> str;
    for(char c : str)
        v.push_back(c - '0');

    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << "\n";
}
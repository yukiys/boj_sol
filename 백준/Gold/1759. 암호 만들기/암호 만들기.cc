#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char alpha[15];
char ans[15];

void init();
void dfs(int, int);

int main()
{
    init();
    dfs(0, 0);
}

void init()
{
    cin >> L >> C;

    for(int i = 0; i < C; i++)
        cin >> alpha[i];

    sort(alpha, alpha + C);
}

void dfs(int idx, int depth)
{
    if(depth == L)
    {
        int vowels = 0, consonants = 0;
        for(int i = 0; i < L; i++)
        {
            if(ans[i] == 'a' or ans[i] == 'e' or ans[i] == 'i' or ans[i] == 'o' or ans[i] == 'u')
                vowels++;
            else
                consonants++;
        }
        if(vowels < 1 or consonants < 2)
            return;

        for(int i = 0; i < L; i++)
            cout << ans[i];
        cout << "\n";

        return;
    }

    for(int i = idx; i < C; i++)
    {
        ans[depth] = alpha[i];
        dfs(i + 1, depth + 1);
    }
}
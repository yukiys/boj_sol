#include <iostream>

using namespace std;

int N, ans = 1e9;
bool selected[15], bestSelected[15];
int mp, mf, ms, mv;
int curMp, curMf, curMs, curMv;
int nutrients[15][5];

void init();
void solve();
void dfs(int, int);
bool isAns();
void printAns();

int main()
{
    init();
    solve();
    printAns();
}

void init()
{
    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < 5; j ++)
            cin >> nutrients[i][j];
}

void solve()
{
    for(int i = 0; i < N; i++)
        dfs(i, 0);
}

void dfs(int index, int cost)
{
    bool goDeep = true;

    curMp += nutrients[index][0];
    curMf += nutrients[index][1];
    curMs += nutrients[index][2];
    curMv += nutrients[index][3];
    selected[index] = true;
    int nextCost = cost + nutrients[index][4];

    if(nextCost >= ans)
        goDeep = false;

    if(isAns() and ans > nextCost)
    {
        ans = nextCost;
        for(int i = 0; i < 15; i++)
            bestSelected[i] = selected[i];

        goDeep = false;
    }
    
    if(goDeep)
        for(int i = index+1; i < N; i++)
            dfs(i, nextCost);
    
    curMp -= nutrients[index][0];
    curMf -= nutrients[index][1];
    curMs -= nutrients[index][2];
    curMv -= nutrients[index][3];
    selected[index] = false;
}

bool isAns()
{
    return curMp >= mp and curMf >= mf and curMs >= ms and curMv >= mv;
}

void printAns()
{
    if(ans != 1e9)
    {
        cout << ans << "\n";
        for(int i = 0; i < 15; i++)
            if(bestSelected[i])
                cout << i + 1 << " ";
        cout << "\n";
    }
    else
        cout << "-1" << "\n";
}
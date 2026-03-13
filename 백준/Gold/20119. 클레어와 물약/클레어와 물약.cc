#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, L;
vector<int> usedIn[200001];
int need[200001];
int resultOf[200001];
bool have[200001];

void init();
void solve();
void printAns();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    solve();
    printAns();
}

void init()
{
    cin >> N >> M;

    for(int i = 1; i <= M; i++)
    {
        int K, x, r;
        cin >> K;
        for(int k = 0; k < K; k++)
        {
            cin >> x;
            usedIn[x].push_back(i);
        }
        cin >> r;

        need[i] = K;
        resultOf[i] = r;
    }

    cin >> L;
    for(int i = 0; i < L; i++)
    {
        int y;
        cin >> y;
        have[y] = true;
    }
}

void solve()
{
    queue<int> q;

    for(int i = 1; i <= N; i++)
        if(have[i])
            q.push(i);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int recipe : usedIn[cur])
        {
            if(--need[recipe] == 0)
            {
                int recipeResult = resultOf[recipe];
                if(!have[recipeResult])
                {
                    have[recipeResult] = true;
                    q.push(recipeResult);
                }
            }
        }
    }
}

void printAns()
{
    int size = 0;
    for(int i = 1; i <= N; i++)
        if(have[i])
            size++;

    cout << size << "\n";
    for(int i = 1; i <= N; i++)
        if(have[i])
            cout << i << " ";
    cout << "\n";
}
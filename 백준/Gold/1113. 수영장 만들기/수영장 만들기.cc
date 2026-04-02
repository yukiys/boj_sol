#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, Size, ans;
int grid[50][50];
bool visited[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init();
void solve();
bool bfs(int, int, int);
void printAns();

int main()
{
    init();
    solve();
    printAns();
}

void init()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            char g;
            cin >> g;
            grid[i][j] = g - '0';
        }
    }
}

void solve()
{
    for(int h = 2; h <= 9; h++)
    {
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(!visited[i][j] and grid[i][j] < h)
                {
                    Size = 0;
                    if(!bfs(h, i, j))
                        ans += Size;
                }
            }
        }
    }
}

bool bfs(int h, int a, int b)
{
    bool leak = false;

    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    Size++;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == 0 or x == N - 1 or y == 0 or y == M - 1)
            leak = true;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 or nx >= N or ny < 0 or ny >= M or visited[nx][ny] or grid[nx][ny] >= h)
                continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            Size++;
        }
    }

    return leak;
}

void printAns()
{
    cout << ans << "\n";
}
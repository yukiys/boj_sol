#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, ans[4];
int grid[1000][1000];
int dist[1000][1000];
vector<pair<int, int>> virus1;
vector<pair<int, int>> virus2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init();
void solve();
void bfs();
void printAns();

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

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
            cin >> grid[i][j];

            if(grid[i][j] == 1)
                virus1.push_back({i, j});
            if(grid[i][j] == 2)
                virus2.push_back({i, j});

            dist[i][j] = -1;
        }
    }
}

void solve()
{
    bfs();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(ans[grid[i][j]] >= 0)
                ans[grid[i][j]]++;
}

void bfs()
{
    queue<pair<int, int>> q;
    
    for(auto[x, y] : virus1)
    {
        dist[x][y] = 0;
        q.push({x, y});
    }
    for(auto[x, y] : virus2)
    {
        dist[x][y] = 0;
        q.push({x, y});
    }

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if(grid[x][y] == 3)
            continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 or nx >= N or ny < 0 or ny >= M)
                continue;
            
            if(dist[nx][ny] == -1)
            {
                if(grid[nx][ny] != 0)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                grid[nx][ny] = grid[x][y];
                q.push({nx, ny});
            }
            else
            {
                if(dist[nx][ny] == dist[x][y] + 1 and grid[nx][ny] != grid[x][y] and grid[nx][ny] != 3)
                    grid[nx][ny] = 3;
            }
        }
    }
}

void printAns()
{
    cout << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
}
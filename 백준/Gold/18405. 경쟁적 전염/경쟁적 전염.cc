#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int S, X, Y;
int grid[201][201];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, pair<int, int>>> virus;

void init();
void bfs();
void printAns();

int main()
{
    init();
    bfs();
    printAns();
}

void init()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] != 0)
                virus.push_back({grid[i][j], {i, j}});
        }
    }
    sort(virus.begin(), virus.end());

    cin >> S >> X >> Y;
}

void bfs()
{
    queue<pair<int, pair<int, int>>> q;
    for(int i = 0; i < virus.size(); i++)
        q.push({0, {virus[i].second.first, virus[i].second.second}});

    while(!q.empty())
    {
        int s = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if(s >= S)
            continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 or nx > N or ny <= 0 or ny > N or grid[nx][ny] != 0)
                continue;

            grid[nx][ny] = grid[x][y];
            q.push({s + 1, {nx, ny}});
        }
    }
}

void printAns()
{
    cout << grid[X][Y] << "\n";
}
#include <string>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int oilId[500][500];
vector<int> oilSize;
bool visited[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int, int, int, vector<vector<int>>&);

int solution(vector<vector<int>> land) {
    int answer = 0;

    n = land.size();
    m = land[0].size();

    memset(oilId, -1, sizeof(oilId));

    int id = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] || land[i][j] == 0)
                continue;

            int Size = bfs(i, j, id, land);
            oilSize.push_back(Size);
            id++;
        }
    }

    int used[id];
    for(int j = 0; j < m; j++)
    {
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            int curId = oilId[i][j];
            if(curId == -1)
                continue;

            if(used[curId] == j)
                continue;

            used[curId] = j;
            sum += oilSize[curId];
        }

        answer = max(answer, sum);
    }

    return answer;
}

int bfs(int a, int b, int id, vector<vector<int>>& land)
{
    if(visited[a][b] || land[a][b] == 0)
        return false;

    queue<pair<int, int>> q;
    q.push({a, b});
    oilId[a][b] = id;
    visited[a][b] = true;

    int cnt = 1;

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(visited[nx][ny] || land[nx][ny] == 0)
                continue;

            q.push({nx, ny});
            oilId[nx][ny] = id;
            visited[nx][ny] = true;
            cnt++;
        }
    }
    
    return cnt;
}
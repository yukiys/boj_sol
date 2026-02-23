#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int X, Y, Z;
int grid[11][11];
int A[11][11];
vector<int> trees[11][11];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void init();
void solve();
void springAndSummer();
void autumn();
void winter();
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
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            grid[i][j] = 5;
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < M; i++)
    {
        cin >> X >> Y >> Z;
        trees[X][Y].push_back(Z);
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            sort(trees[i][j].begin(), trees[i][j].end());
}

void solve()
{
    while(K--)
    {
        springAndSummer();
        autumn();
        winter();
    }
}

void springAndSummer()
{
    for(int x = 1; x <= N; x++)
    {
        for(int y = 1; y <= N; y++)
        {
            if(trees[x][y].empty())
                continue;
            
            vector<int> alive;
            alive.reserve(trees[x][y].size());
            int cur = grid[x][y];
            int deadFood = 0;
            bool isDie = false;

            for(int age : trees[x][y])
            {
                if(!isDie and cur >= age)
                {
                    cur -= age;
                    alive.push_back(age + 1);
                }
                else
                {
                    isDie = true;
                    deadFood += age / 2;
                }
            }

            grid[x][y] = cur + deadFood;
            trees[x][y].swap(alive);
        }
    }
}

void autumn()
{
    int born[11][11] = {0};
    
    for(int x = 1; x <= N; x++)
    {
        for(int y = 1; y <= N; y++)
        {
            for(int age : trees[x][y])
            {
                if(age % 5 != 0)
                    continue;

                for(int d = 0; d < 8; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx <= 0 or nx > N or ny <= 0 or ny > N)
                        continue;
                    
                    born[nx][ny]++;
                }
            }
        }
    }

    for(int x = 1; x <= N; x++)
    {
        for(int y = 1; y <= N; y++)
        {
            int b = born[x][y];
            if(b == 0)
                continue;

            vector<int> v;
            v.reserve(b + trees[x][y].size());
            v.assign(b, 1);
            v.insert(v.end(), trees[x][y].begin(), trees[x][y].end());
            trees[x][y].swap(v);
        }
    }
}

void winter()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            grid[i][j] += A[i][j];
}

void printAns()
{
    long long ans = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            ans += trees[i][j].size();

    cout << ans << "\n";
}
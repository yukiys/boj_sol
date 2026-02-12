#include <iostream>
#include <cmath>

using namespace std;

int N, M, ret = -1;
int grid[9][9];

void init()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            char c;
            cin >> c;

            grid[i][j] = c - '0';
        }
    }
}

bool isSquare(int num){
    int n = (int)sqrt(num);

    return n * n == num;
}

void solve(){
    const int weight = 10;
    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y < M; y++)
        {
            for(int dx = -(N-1); dx <= (N-1); dx++)
            {
                for(int dy = -(M-1); dy <= (M-1); dy++)
                {
                    if(dx == 0 and dy == 0)
                    {
                        int num = grid[x][y];
                        if(isSquare(num))
                            ret = max(ret, num);
                        continue;
                    }
                    
                    int num = 0;
                    int cx = x, cy = y;
                    while(0 <= cx and cx < N and 0 <= cy and cy < M)
                    {
                        num = weight * num + grid[cx][cy];
                        if(isSquare(num))
                            ret = max(ret, num);

                        cx += dx;
                        cy += dy;
                    }
                }
            }
        }
    }
}

void printRet()
{
    cout << ret << "\n";
}

int main()
{
    init();
    solve();
    printRet();
}
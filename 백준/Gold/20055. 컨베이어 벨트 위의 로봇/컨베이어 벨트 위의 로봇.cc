#include <iostream>

using namespace std;

int N, K, zero, ans;
int A[201];
bool isExist[201];
int robotIdx[201];
int robotCount;

void init();
void solve();
int nextPos(int);
void eraseRobot(int);
void rotateBelt();
void moveRobots();
void putRobot();
bool isFinished();
void printAns();

int main()
{
    init();
    solve();
    printAns();
}

void init()
{
    cin >> N >> K;
    for(int i = 1; i <= 2 * N; i++)
        cin >> A[i];
}

void solve()
{
    while(true)    
    {
        ans++;

        rotateBelt();
        moveRobots();
        putRobot();

        if(isFinished())
            break;
    }
}

int nextPos(int x)
{
    return x % (2 * N) + 1;
}

void eraseRobot(int x)
{
    isExist[robotIdx[x]] = false;
    for(int i = x; i < robotCount; i++)
        robotIdx[i] = robotIdx[i + 1];
    robotCount--;
}

void rotateBelt()
{
    int last = A[2 * N];
    for(int i = 2 * N; i >= 2; i--)
        A[i] = A[i - 1];
    A[1] = last;

    for(int i = 1; i <= robotCount; i++)
        isExist[robotIdx[i]] = false;

    for(int i = 1; i <= robotCount; i++)
    {
        robotIdx[i] = nextPos(robotIdx[i]);
        isExist[robotIdx[i]] = true;
    }

    if(robotCount > 0 && robotIdx[1] == N)
        eraseRobot(1);
}

void moveRobots()
{
    for(int i = 1; i <= robotCount; i++)
    {
        int cur = robotIdx[i];
        int idx = nextPos(cur);

        if(A[idx] == 0 or isExist[idx])
            continue;
        
        isExist[robotIdx[i]] = false;
        if(--A[idx] == 0)
            zero++;
        
        if(idx == N)
        {
            for(int j = i; j < robotCount; j++)
                robotIdx[j] = robotIdx[j + 1];
            robotCount--;
            i--;
        }
        else
        {
            robotIdx[i] = idx;
            isExist[idx] = true;
        }
    }
}

void putRobot()
{
    if(A[1] >= 1 and !isExist[1])
    {
        if(--A[1] == 0)
            zero++;

        isExist[1] = true;
        robotIdx[++robotCount] = 1;
    }
}

bool isFinished()
{
    return zero >= K;
}

void printAns()
{
    cout << ans << "\n";
}
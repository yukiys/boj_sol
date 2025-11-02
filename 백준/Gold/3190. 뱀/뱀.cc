#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N,K,L,curDir,ret,T0;
int grid[101][101];
pair<int,int> dir[4]={{0,1},{1,0},{0,-1},{-1,0}}; //R,D,L,U 
deque<pair<int,int>> snake;
vector<pair<int,char>> steps;

void input()
{
    cin>>N>>K;
    for(int i=0;i<K;i++)
    {
        int a,b;
        cin>>a>>b;
        grid[a][b]=1;
    }

    cin>>L;
    for(int i=0;i<L;i++)
    {
        int T;
        char op;
        cin>>T>>op;
        steps.push_back({T,op});
    }
}

bool stopCheck(int a,int b)
{
    if(a<1 or a>N or b<1 or b>N) return true;
    for(int i=0;i<snake.size();i++)
        if(a==snake[i].first and b==snake[i].second)
            return true;
    return false;
}

void changeDir(char op)
{
    if(op=='D') curDir=(curDir+1)%4;
    if(op=='L') curDir=(curDir+3)%4;
}

bool move()
{
    int a=snake.front().first;
    int b=snake.front().second;
    ret++;

    int na=a+dir[curDir].first;
    int nb=b+dir[curDir].second;

    if(stopCheck(na,nb)) return false;
    snake.push_front({na,nb});

    if(grid[na][nb]==1) grid[na][nb]=0;
    else snake.pop_back();

    return true;
}

void solve()
{
    snake.push_back({1,1});
    for(int l=0;l<L;l++)
    {
        int T=steps[l].first-T0;
        T0=steps[l].first;
        char op=steps[l].second;

        for(int t=0;t<T;t++)
            if(!move())
                return;
        changeDir(op);
    }

    while(move());
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}
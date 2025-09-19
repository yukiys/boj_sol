#include <iostream>
#include <cstring>

using namespace std;

int R,C,T;
int airCleaner;
int grid[50][50];
int temp[50][50];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

void input()
{
    cin>>R>>C>>T;
    for(int r=0;r<R;r++)
    {
        for(int c=0;c<C;c++)
        {
            cin>>grid[r][c];
            if(grid[r][c]==-1) airCleaner=r;
        }
    }
}

void Diffusion()
{
    memset(temp,0,sizeof(temp));

    for(int r=0;r<R;r++)
    {
        for(int c=0;c<C;c++)
        {
            int t=grid[r][c];
            if(t<=0) continue;
            if((t/=5)<=0) continue;

            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0 or nr>=R or nc<0 or nc>=C or grid[nr][nc]==-1) continue;

                temp[nr][nc]+=t;
                temp[r][c]-=t;
            }
        }
    }

    for(int r=0;r<R;r++)
        for(int c=0;c<C;c++)
            if(grid[r][c]!=-1)
                grid[r][c]+=temp[r][c];
}

void AirCleaner()
{
    int r=airCleaner-1,c=0;
    int dir1[4][2]={{0,1},{-1,0},{0,-1},{1,0}};

    int t=0,i=0;
    while(1)
    {
        r+=dir1[i][0];
        c+=dir1[i][1];
        if(c>=C or r<0 or c<0)
        {
            r-=dir1[i][0];
            c-=dir1[i][1];
            i++;
            continue;
        }

        if(r==airCleaner-1 and c==0) break;

        int tmp=grid[r][c];
        grid[r][c]=t;
        t=tmp;
    }

    r=airCleaner,c=0;
    int dir2[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

    t=0,i=0;
    while(1)
    {
        r+=dir2[i][0];
        c+=dir2[i][1];
        if(c>=C or r>=R or c<0)
        {
            r-=dir2[i][0];
            c-=dir2[i][1];
            i++;
            continue;
        }

        if(r==airCleaner and c==0) break;

        int tmp=grid[r][c];
        grid[r][c]=t;
        t=tmp;
    }
}

int Count()
{
    int cnt=0;
    for(int r=0;r<R;r++)
        for(int c=0;c<C;c++)
            if(grid[r][c]!=-1)
                cnt+=grid[r][c];
    return cnt;
}

void printResult()
{
    cout<<Count()<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    while(T--)
    {
        Diffusion();
        AirCleaner();
    }
    printResult();

    return 0;
}
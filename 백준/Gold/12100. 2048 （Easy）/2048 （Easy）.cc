#include <iostream>

using namespace std;

int N,ret;
int grid[20][20];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>grid[i][j];
}

void moveLeft()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==0) continue;
            
            for(int k=1;j+k<N;k++)
            {
                if(grid[i][j+k]==0) continue;
                else if(grid[i][j]==grid[i][j+k])
                {
                    grid[i][j]*=2;
                    grid[i][j+k]=0;
                    j+=k;
                    break;
                }
                break;
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        int row[20],idx=0;
        for(int j=0;j<N;j++)
            if(grid[i][j]!=0)
                row[idx++]=grid[i][j];

        for(int j=0;j<N;j++) grid[i][j]=j<idx?row[j]:0;
    }
}

void moveRight()
{
    for(int i=0;i<N;i++)
    {
        for(int j=N-1;j>=0;j--)
        {
            if(grid[i][j]==0) continue;

            for(int k=1;j-k>=0;k++)
            {
                if(grid[i][j-k]==0) continue;
                else if(grid[i][j]==grid[i][j-k])
                {
                    grid[i][j]*=2;
                    grid[i][j-k]=0;
                    j-=k;
                    break;
                }
                break;
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        int row[20],idx=N-1;
        for(int j=N-1;j>=0;j--)
            if(grid[i][j]!=0)
                row[idx--]=grid[i][j];

        for(int j=N-1;j>=0;j--) grid[i][j]=j>idx?row[j]:0;
    }
}

void moveUp()
{
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(grid[i][j]==0) continue;

            for(int k=1;i+k<N;k++)
            {
                if(grid[i+k][j]==0) continue;
                else if(grid[i][j]==grid[i+k][j])
                {
                    grid[i][j]*=2;
                    grid[i+k][j]=0;
                    i+=k;
                    break;
                }
                break;
            }
        }
    }

    for(int j=0;j<N;j++)
    {
        int col[20],idx=0;
        for(int i=0;i<N;i++)
            if(grid[i][j]!=0)
                col[idx++]=grid[i][j];

        for(int i=0;i<N;i++) grid[i][j]=i<idx?col[i]:0;
    }
}

void moveDown()
{
    for(int j=0;j<N;j++)
    {
        for(int i=N-1;i>=0;i--)
        {
            if(grid[i][j]==0) continue;

            for(int k=1;i-k>=0;k++)
            {
                if(grid[i-k][j]==0) continue;
                else if(grid[i][j]==grid[i-k][j])
                {
                    grid[i][j]*=2;
                    grid[i-k][j]=0;
                    i-=k;
                    break;
                }
                break;
            }
        }
    }

    for(int j=0;j<N;j++)
    {
        int col[20],idx=N-1;
        for(int i=N-1;i>=0;i--)
            if(grid[i][j]!=0)
                col[idx--]=grid[i][j];

        for(int i=N-1;i>=0;i--) grid[i][j]=i>idx?col[i]:0;
    }
}

void updateMax()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ret=max(ret,grid[i][j]);
}

void dfs(int depth)
{
    if(depth==5)
    {
        updateMax();
        return;
    }

    int temp[20][20];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            temp[i][j]=grid[i][j];


    moveLeft();
    dfs(depth+1);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            grid[i][j]=temp[i][j];

    moveRight();
    dfs(depth+1);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            grid[i][j]=temp[i][j];

    moveUp();
    dfs(depth+1);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            grid[i][j]=temp[i][j];

    moveDown();
    dfs(depth+1);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            grid[i][j]=temp[i][j];
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    dfs(0);
    printResult();

    return 0;
}
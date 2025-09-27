#include <iostream>

using namespace std;

int sudoku[9][9];
bool untouch[9][9];

void input()
{
    for(int r=0;r<9;r++)
    {
        for(int c=0;c<9;c++)
        {
            scanf("%1d",&sudoku[r][c]);
            if(sudoku[r][c]!=0) untouch[r][c]=true;
        }
    }
}

bool check(int R,int C,int num)
{
    for(int r=0;r<9;r++)
        if(sudoku[r][C]==num)
            return false;

    for(int c=0;c<9;c++)
        if(sudoku[R][c]==num)
            return false;

    R=(R/3)*3;
    C=(C/3)*3;
    for(int r=0;r<3;r++)
        for(int c=0;c<3;c++)
            if(sudoku[R+r][C+c]==num)
                return false;

    return true;
}

bool dfs(int R,int C)
{
    if(R==9) return true;

    int nR=R,nC=C+1;
    if(C+1==9)
    {
        nC=0;
        nR++;
    }

    if(untouch[R][C]) return dfs(nR,nC);

    for(int n=1;n<=9;n++)
    {
        if(check(R,C,n))
        {
            sudoku[R][C]=n;
            if(dfs(nR,nC)) return true;
            sudoku[R][C]=0;
        }
    }

    return false;
}

void printResult()
{
    for(int r=0;r<9;r++)
    {
        for(int c=0;c<9;c++) cout<<sudoku[r][c];
        cout<<"\n";
    }
}

int main()
{
    input();
    dfs(0,0);
    printResult();

    return 0;
}
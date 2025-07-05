#include <iostream>

using namespace std;

int R,C,K;
int ret;
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
char map[5][5];

void dfs(int r,int c,int len)
{
    if(r==0 and c==C-1 and len==K)
    {
        ret++;
        return;
    }
    if(len>=K) return;

    char before=map[r][c];
    map[r][c]='1';

    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];

        if(nr<0 or nr>=R or nc<0 or nc>=C or map[nr][nc]=='1' or map[nr][nc]=='T') continue;
        
        dfs(nr,nc,len+1);
    }

    map[r][c]=before;
}

int main()
{
    cin>>R>>C>>K;

    for(int r=0;r<R;r++)
        for(int c=0;c<C;c++)
            cin>>map[r][c];

    dfs(R-1,0,1);

    cout<<ret<<"\n";

    return 0;
}
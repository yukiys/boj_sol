#include <iostream>

using namespace std;

int map[5][5];
int r,c;
int mOflen=100000000;
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

void dfs(int r,int c,int cnt,int len)
{
    if(cnt==3)
    {
        mOflen=min(mOflen,len);
        return;
    }

    if(len>=mOflen) return;

    int before=map[r][c];
    map[r][c]=-1;

    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];

        if(nr<0 or nr>=5 or nc<0 or nc>=5 or map[nr][nc]==-1) continue;
        
        if(map[nr][nc]==1) dfs(nr,nc,cnt+1,len+1);
        else dfs(nr,nc,cnt,len+1);
    }

    map[r][c]=before;
}

int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>map[i][j];

    cin>>r>>c;
    dfs(r,c,0,0);

    if(mOflen==100000000) cout<<"-1\n";
    else cout<<mOflen<<"\n";

    return 0;
}
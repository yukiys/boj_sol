#include <iostream>

using namespace std;

int R,C;
char map[20][20];
int Alphabet[26];
bool visited[20][20];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
int ret;

void backTracking(int r,int c,int depth)
{
    if(ret<depth) ret=depth;
    if(visited[r][c]) return;
    visited[r][c]=true;
    Alphabet[map[r][c]-'A']=1;

    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];

        if(nr<0 or nr>=R or nc<0 or nc>=C or Alphabet[map[nr][nc]-'A']==1 or visited[nr][nc]) continue;
        backTracking(nr,nc,depth+1);
    }

    visited[r][c]=false;
    Alphabet[map[r][c]-'A']=0;
}

int main()
{
    cin>>R>>C;
    for(int r=0;r<R;r++)
        for(int c=0;c<C;c++)
            cin>>map[r][c];

    backTracking(0,0,1);

    cout<<ret<<"\n";

    return 0;
}
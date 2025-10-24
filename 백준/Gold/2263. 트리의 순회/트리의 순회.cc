#include <iostream>

using namespace std;

int N;
int inOrder[100000],postOrder[100000];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>inOrder[i];
    for(int i=0;i<N;i++) cin>>postOrder[i];
}

void preOrder(int iLeft,int iRight,int pLeft,int pRight)
{
    if(iLeft>iRight or pLeft>pRight) return;

    int root=postOrder[pRight];
    int iRoot;
    for(int i=iLeft;i<=iRight;i++)
    {
        if(inOrder[i]==root)
        {
            iRoot=i;
            break;
        }
    }

    int left=iRoot-iLeft;

    cout<<root<<" ";
    preOrder(iLeft,iRoot-1,pLeft,pLeft+left-1);
    preOrder(iRoot+1,iRight,pLeft+left,pRight-1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    preOrder(0,N-1,0,N-1);

    return 0;
}
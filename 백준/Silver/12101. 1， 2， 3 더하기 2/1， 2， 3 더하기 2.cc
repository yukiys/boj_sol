#include <iostream>
#include <vector>

using namespace std;

int n,k;
int cnt;
int arr[3]={1,2,3};
vector<int> Arr;

void dfs(int m)
{
    if(m>n) return;
    if(m==n)
    {
        cnt++;
        if(cnt==k)
        {
            for(int i=0;i<Arr.size();i++)
            {
                cout<<Arr[i];
                if(i!=Arr.size()-1) cout<<"+";
            }
            cout<<"\n";
        }
    }

    for(int i=0;i<3;i++)
    {
        Arr.push_back(arr[i]);
        dfs(m+arr[i]);
        Arr.pop_back();
    }
}

int main()
{
    cin>>n>>k;

    dfs(0);

    if(cnt==0 or cnt<k) cout<<"-1\n";

    return 0;
}
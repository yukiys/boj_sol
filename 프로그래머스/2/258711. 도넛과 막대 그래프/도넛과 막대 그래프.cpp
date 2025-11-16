#include <string>
#include <vector>

using namespace std;

int a0,a1,a2,a3,sum;
int degree[1000001];
vector<int> G[1000001];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    for(int i=0;i<edges.size();i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];

        degree[a]++;
        degree[b]--;

        G[a].push_back(b);
    }

    for(int i=1;i<=1000000;i++)
    {
        if(degree[i]>=2)
        {
            a0=i;
            sum=degree[a0];
            break;
        }
    }

    for(int i:G[a0])
    {
        int cur=i;
        while(1)
        {
            if(G[cur].empty())
            {
                a2++;
                break;
            }
            if(G[cur].size()==2)
            {
                a3++;
                break;
            }
            cur=G[cur][0];
            if(cur==i) break;
        }
    }
    
    a1=sum-a2-a3;
    answer.push_back(a0);
    answer.push_back(a1);
    answer.push_back(a2);
    answer.push_back(a3);
    
    return answer;
}
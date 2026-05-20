#include <string>
#include <vector>

using namespace std;

bool used[31];
void dfs(int, int, vector<vector<int>>&, vector<int>&);
int N, M, answer;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N = n;
    M = q.size();
    dfs(0, 1, q, ans);

    return answer;
}

void dfs(int depth, int start, vector<vector<int>>& q, vector<int>& ans)
{
    if(depth == 5)
    {
        for(int m = 0; m < M; m++)
        {
            int count = 0;
            for(int i = 0; i < 5; i++)
                if(used[q[m][i]])
                    count++;

            if(count != ans[m])
                return;
        }
        
        answer++;
        return;
    }

    for(int i = start; i <= N; i++)
    {
        if(!used[i])
        {
            used[i] = true;
            dfs(depth + 1, i + 1, q, ans);
            used[i] = false;
        }
    }
}
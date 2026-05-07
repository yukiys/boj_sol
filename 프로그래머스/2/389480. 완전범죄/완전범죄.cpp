#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int Size = info.size(), INF = 1e9;
    int answer = INF;

    int dp[41][121];
    for(int i = 0; i <= Size; i++)
        for(int b = 0; b < m; b++)
            dp[i][b] = INF;
    dp[0][0] = 0;

    for(int i = 0; i < Size; i++)
    {
        int addA = info[i][0];
        int addB = info[i][1];
        
        for(int b = 0; b < m; b++)
        {
            if(dp[i][b] == INF)
                continue;

            int nextA = dp[i][b] + addA;
            if(nextA < n)
                dp[i + 1][b] = min(dp[i + 1][b], nextA);

            int nextB = b + addB;
            if(nextB < m)
                dp[i + 1][nextB] = min(dp[i + 1][nextB], dp[i][b]);
        }
    }

    for(int b = 0; b < m; b++)
        answer = min(answer, dp[Size][b]);

    if(answer == INF)
        return -1;
    return answer;
}
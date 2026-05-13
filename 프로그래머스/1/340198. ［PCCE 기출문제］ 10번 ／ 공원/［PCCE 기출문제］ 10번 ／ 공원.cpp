#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.rbegin(), mats.rend());
    int n = park.size();
    int m = park[0].size();

    for(int mat : mats)
    {
        for(int i = 0; i + mat - 1 < n; i++)
        {
            for(int j = 0; j + mat - 1 < m; j++)
            {
                bool check = true;

                for(int di = 0; di < mat; di++)
                {
                    for(int dj = 0; dj < mat; dj++)
                    {
                        if(park[i + di][j + dj] != "-1")
                        {
                            check = false;
                            break;
                        }
                    }
                    if(!check)
                        break;
                }

                if(check)
                    return mat;
            }
        }
    }

    return -1;
}
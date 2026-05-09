#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    int height = (n + w - 1) / w;
    vector<vector<int>> box(height, vector<int>(w, 0));

    int targetRow = 0;
    int targetCol = 0;

    for(int i = 1; i <= n; i++)
    {
        int row = (i - 1) / w;
        int idx = (i - 1) % w;

        int col;
        if(row % 2 == 0)
            col = idx;
        else
            col = w - 1 - idx;

        box[row][col] = i;

        if(i == num)
        {
            targetRow = row;
            targetCol = col;
        }
    }

    for(int r = targetRow; r < height; r++)
        if(box[r][targetCol] != 0)
            answer++;

    return answer;
}
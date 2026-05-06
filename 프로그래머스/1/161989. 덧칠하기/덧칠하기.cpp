#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int idx = 0;
    int Size = section.size();

    while(idx <= n)
    {
        int cur = section[idx];
        answer++;
        cur += (m - 1);

        if(cur >= n)
            break;

        while(section[idx] <= cur)
            idx++;

        if(idx >= Size)
            break;
    }

    return answer;
}
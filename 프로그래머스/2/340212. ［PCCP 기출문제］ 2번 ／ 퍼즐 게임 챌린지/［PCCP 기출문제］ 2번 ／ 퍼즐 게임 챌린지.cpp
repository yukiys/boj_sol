#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int n = diffs.size();
    int left = 1, right = 100000;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        long long prev_time = 0, total = 0;
        for(int i = 0; i < n ; i++)
        {
            int diff = diffs[i];
            int time = times[i];

            if(mid < diff)
                total += (diff - mid) * (prev_time + time);
            total += time;
            
            prev_time = time;
        }

        if(total <= limit)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}
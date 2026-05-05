#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();

    for(int i = 0; i < n; i++)
    {
        int limitHour = schedules[i] / 100;
        int limitMin = schedules[i] % 100 + 10;
        if(limitMin >= 60)
        {
            limitHour++;
            limitMin -= 60;
        }

        for(int d = 0; d < 7; d++)
        {
            int day = (startday + d) % 7;
            if(day == 6 || day == 0)
            {
                if(d == 6)
                    answer++;
                continue;
            }

            int curHour = timelogs[i][d] / 100;
            int curMin = timelogs[i][d] % 100;

            if(limitHour < curHour)
                break;
            if(limitHour == curHour && limitMin < curMin)
                break;

            if(d == 6)
                answer++;
        }
    }

    return answer;
}
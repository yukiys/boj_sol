#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    map<tuple<int, int, int>, int> visited;

    for(auto route : routes)
    {
        int time = 0;

        int start = route[0] - 1;
        int r = points[start][0];
        int c = points[start][1];

        visited[{time, r, c}]++;

        for(int i = 1; i < route.size(); i++)
        {
            int target = route[i] - 1;
            int tr = points[target][0];
            int tc = points[target][1];

            while(r != tr)
            {
                if(r < tr)
                    r++;
                else
                    r--;

                visited[{++time, r, c}]++;
            }

            while(c != tc)
            {
                if(c < tc)
                    c++;
                else
                    c--;

                visited[{++time, r, c}]++;
            }
        }
    }

    for(auto [key, count] : visited)
        if(count >= 2)
            answer++;
    
    return answer;
}
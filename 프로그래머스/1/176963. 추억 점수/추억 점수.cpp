#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    unordered_map<string, int> map;
    for(int i = 0; i < name.size(); i++)
        map[name[i]] = yearning[i];

    for(vector<string> v : photo)
    {
        int score = 0;
        for(string s : v)
            if(map.find(s) != map.end())
                score += map[s];

        answer.push_back(score);
    }
    
    return answer;
}
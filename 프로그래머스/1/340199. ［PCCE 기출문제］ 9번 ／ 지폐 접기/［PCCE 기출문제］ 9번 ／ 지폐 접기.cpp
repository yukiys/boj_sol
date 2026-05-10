#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    int wallMin = min(wallet[0], wallet[1]);
    int wallMax = max(wallet[0], wallet[1]);
    int bill0 = bill[0];
    int bill1 = bill[1];

    while(min(bill0, bill1) > wallMin || max(bill0, bill1) > wallMax)
    {
        if(bill0 > bill1)
            bill0 /= 2;
        else
            bill1 /= 2;
        answer++;
    }

    return answer;
}
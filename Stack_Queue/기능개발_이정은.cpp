#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    double day;
    int count, a;
    for (int i = 0; i < progresses.size(); i++) {
        day = 100 - progresses[i];
        day = ceil(day / speeds[i]);
        days.push_back(day);
    }


    while (days.size() != 0) {
        a = days[0];
        count = 0;
        for (auto iter = days.begin(); iter != days.end(); ) {
            if ((*iter) <= a) {
                count++;
                iter = days.erase(iter);
            }
            else
                break;
        }
        answer.push_back(count);
    }
    return answer;
}
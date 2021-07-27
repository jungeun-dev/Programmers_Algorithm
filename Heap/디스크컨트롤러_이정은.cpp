#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int total = 0;
    int i;
    vector <pair <int, int>> js;

    for (int i = 0; i < jobs.size(); i++) {
        js.push_back(make_pair(jobs[i][1], jobs[i][0])); // <작업 소요 시간, 작업 요청 시간>
    }
    sort(js.begin(), js.end()); // 작업 소요시간 오름차순으로 정렬됨

    while (!js.empty()) {
        for (i = 0; i < js.size(); i++) {
            if (js[i].second <= total) { // 작업 요청시간이 현재 시간보다 작은경우
                total += js[i].first;
                answer += (total - js[i].second);
                js.erase(js.begin() + i);
                break;
            }
            if (i == js.size() - 1) total++;
        }
        //if(i == js.size()) total++;        
    }

    answer /= jobs.size(); //걸린시간 평균
    return answer;
}
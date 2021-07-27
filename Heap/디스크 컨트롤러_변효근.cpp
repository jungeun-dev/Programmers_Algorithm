#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class compare { // 정렬 방식을 만듬. 오름차순
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        }
};
class compare2 { // 정렬 방식을 만듬. 오름차순
public:
    bool operator()(pair<int, int> ㄴa, pair<int, int> b) {
        return a.second > b.second;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue< pair<int, int>, vector<pair<int, int>>, compare > wait; // 대기 큐
    priority_queue< pair<int, int>, vector<pair<int, int>>, compare2 > run; // 진행 큐

    for (int i = 0;i < jobs.size();i++)
        wait.push(make_pair(jobs[i][0], jobs[i][1])); // pair의 형태로 wait queue에 넣음.

    int time = 0; // 디스크 컨트롤러의 시간을 나타내는 변수.

    // 문제를 푼 방식
    // 이 문제는 작업이 끊기지 않는 선에서
    // 가장 적은 시간의 작업을 먼저 진행하도록 해야한다.
    // 그 시간에  wait queue에서 가능한 작업들을 run queue에 넣는다.
    // wait queue는 요청이 온 시간이 빠른 순으로 정렬하도록 설계 되어있고
    // run queue는 작업시간이 빠른 순으로 정렬되도록 설계되어있다.
    // time을 통해 요청시간을 비교하고 작업 가능한 작업들을 run queue에 넣고
    // run queue에서 가장 앞 ,즉 작업시간이 작은 작업을 먼저 진행하도록 만들었다.

    while(!wait.empty() || !run.empty() ){
        while(!wait.empty() && wait.top().first <= time) { // 요청 시간과 비교하여
            run.push(wait.top());                          // 작업가능한 작업들을
            wait.pop();                                    // run queue로 넣음.
        }
        if (!run.empty()) {                                // run queue가 비어있지 않다면
            time += run.top().second;                      // 가장 앞 데이터를 빼서
            answer += time - run.top().first;              // time에 더해준다.
            run.pop();
            continue;
        }
        time++;  // 만약 run queue가 비어있다면 1ms씩 시간을 늘려준다.
    }

    return answer/jobs.size();
}

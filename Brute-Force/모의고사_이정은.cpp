#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> st1 = { 1,2,3,4,5 }; // 5 
    vector<int> st2 = { 2,1,2,3,2,4,2,5 }; //8
    vector<int> st3 = { 3,3,1,1,2,2,4,4,5,5 }; // 10
    vector<int> cnt = { 0,0,0 };

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == st1[i % 5]) cnt[0]++;
        if (answers[i] == st2[i % 8]) cnt[1]++;
        if (answers[i] == st3[i % 10]) cnt[2]++;
    }
    answer.push_back(1);

    for (int i = 1; i < 3; i++) {
        if (cnt[i] > cnt[answer[0] - 1]) { // 이미 answer에 들어가있는 수포자의 맞춘문제보다 많은지 확인
            answer.clear();
            answer.push_back(i + 1);
        }
        else if (cnt[i] == cnt[answer[0] - 1]) { // 최다득점이 여러명인경우
            answer.push_back(i + 1);
        }
    }

    return answer;
}
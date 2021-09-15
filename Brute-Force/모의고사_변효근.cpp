#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> st1 = { 1, 2, 3, 4, 5 }; // 5개
    vector<int> st2 = { 2, 1, 2, 3, 2, 4, 2, 5 }; // 8개
    vector<int> st3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // 10개

    int st1_score = 0;
    int st2_score = 0;
    int st3_score = 0;

    for (int i = 0; i < answers.size() ; i++) {
        if (st1[i % 5] == answers[i % answers.size()]) st1_score++;
        if (st2[i % 8] == answers[i % answers.size()]) st2_score++;
        if (st3[i % 10] == answers[i % answers.size()]) st3_score++;
    }

    if (st1_score >= st2_score && st1_score >= st3_score) {
        answer.push_back(1);
    }
    if (st2_score >= st1_score && st2_score >= st3_score) {
        answer.push_back(2);
    }
    if (st3_score >= st1_score && st3_score >= st2_score) {
        answer.push_back(3);
    }
    return answer;
}

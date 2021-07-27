#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

 vector<int> solution(vector<string> operations) {
        vector<int> answer;
        deque<int> dq;       // deque를 선언.

        for (int i = 0;i < operations.size();i++) {
            if (operations[i].at(0)=='I'){ // 명령어가 'I' 일 경우
                dq.push_back(stoi(operations[i].substr(2))); // "I ㅁㅁㅁㅁ" I 이후의 숫자를 잘라서 dq에 넣음.
                sort(dq.begin(), dq.end());                  // 우선순위 큐와 같이 정렬시켜줌.
            }

            else { // 명령어가 'D' 일 경우
                if (!dq.empty() && operations[i] == "D 1") dq.pop_back();       // 최댓값 즉 맨 뒤값을 지워줌.
                else if (!dq.empty() && operations[i] == "D -1") dq.pop_front();// 최솟값 즉 맨 앞값을 지워줌.
            }
        }
        if (dq.size()< 2) {
            answer.push_back(0);
            answer.push_back(0);
        }
        else {
            answer.push_back(dq[dq.size() - 1]);
            answer.push_back(dq[0]);
        }
        return answer;
 }

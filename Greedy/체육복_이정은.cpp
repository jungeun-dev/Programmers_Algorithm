#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //여벌의 체육복을 가져온 사람이 도난 당한 경우
    for (int i = 0; i < lost.size(); i++) {
        auto it = find(reserve.begin(), reserve.end(), lost[i]);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost.erase(lost.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] - 1 != 0) {
            auto it = find(lost.begin(), lost.end(), reserve[i] - 1);
            if (it != lost.end()) {
                lost.erase(it);
            }
            else {
                if (reserve[i] != n) {
                    it = find(lost.begin(), lost.end(), reserve[i] + 1);
                    if (it != lost.end()) {
                        lost.erase(it);
                    }
                }
            }
        }
        else {
            auto it = find(lost.begin(), lost.end(), reserve[i] + 1);
            if (it != lost.end()) {
                lost.erase(it);
            }
        }
    }
    answer = n - lost.size();
    return answer;
}
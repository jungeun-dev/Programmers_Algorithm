#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<bool>> info(n + 1, vector<bool>(n + 1, false));
    // 대결 시 진 애들 표시
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        info[i][i] = true;
        while (!q.empty()) {
            int start = q.front();
            q.pop();

            for (vector<int> r : results) {
                if (r[0] == start && !info[i][r[1]]) {
                    info[i][r[1]] = true;
                    q.push(r[1]);
                }
            }
        }
    }
    // 대결시 이긴 애들 표시
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int start = q.front();
            q.pop();

            for (vector<int> r : results) {
                if (r[1] == start && !info[i][r[0]]) {
                    info[i][r[0]] = true;
                    q.push(r[0]);
                }
            }
        }
    }
    for (vector<bool> bools : info) {
        int i = 0;
        for (bool b : bools) {
            if (b == true) i++;
        }
        if (i == n) answer++;
    }
    return answer;

}
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector <vector<int>> r;          //행렬로 풀라고 2차원 벡터.
    for (int i = 0; i < n; i++) {    // 기본 셋팅
        vector <int> r2;             //  1 1 1 1
        if(i==0) r2.assign(m, 1);    //  1 0 0 0
        else {                       //  1 0 0 0
            r2.assign(m, 0);         // 의 형태로 만드는 for문
            r2[0] = 1;
        }
        r.push_back(r2);
    }
    for (vector<int> p : puddles) {   // 웅덩이는 -1로 설정하는데,
        r[p[1] - 1][p[0] - 1] = -1;   // 만약 맨 위행 , 맨 왼열에 웅덩이가 있다면
        if (p[1] == 1) {              // 그 다음 열과 행에는 도달하지 못하므로 0으로 바꿔줌.
            for (int i = p[0]; i < r[0].size(); i++) {
                r[0][i] = 0;
            }                                         // 이해가 안될 것 같으므로 그 예시임.
        }                                             // 1 -1 0 0
        if (p[0] == 1) {                              // 1  0 0 0
            for (int i = p[1]; i < r.size(); i++) {   // 1  0 0 0
                r[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (r[i][j] != -1) {                                  // 문제에서 오른쪽과 아래로만 움직여 만든다고 했으니,
                if (r[i - 1][j] < 0 && r[i][j-1] < 0) r[i][j] = 0;// 해당 지점은 자신의 왼쪽과 위쪽의 경우의 수를 더해서 만듬.
                else if (r[i - 1][j] < 0) r[i][j] = r[i][j - 1];  // 1 1 1 1                     1 1 1 1
                else if (r[i][j - 1] < 0) r[i][j] = r[i - 1][j];  // 1 0 0 0         ->          1 2 3 4
                else r[i][j] = r[i - 1][j] + r[i][j - 1];         // 1 0 0 0                     1 3 6 10
                r[i][j] %= 1000000007;                            // 과 같이 나타날 것임.
            }
        }
    }


    return answer = r[n-1][m-1] % 1000000007;

}

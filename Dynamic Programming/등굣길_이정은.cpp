#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int arr[101][101] = { 0, };


    for (vector<int> puddle : puddles) {
        arr[puddle[1]][puddle[0]] = -1;
    }
    arr[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != -1) {
                arr[i][j] += (arr[i - 1][j] + arr[i][j - 1]) % 1000000007;
                //arr[i][j] = ((arr[i - 1][j] + arr[i][j - 1]) % 1000000007);   
            }
            else arr[i][j] = 0;
        }
    }
    answer = arr[n][m] % 1000000007;
    return answer;
}
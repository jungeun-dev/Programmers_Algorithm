#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    int larger = 0;

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size() - 1; j++) {
            larger = max(triangle[i][j], triangle[i][j + 1]);
            triangle[i - 1][j] += larger;
        }
    }
    answer = triangle[0][0];
    return answer;
}
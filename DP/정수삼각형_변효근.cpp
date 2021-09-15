#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = triangle.size() - 1; i > 0; i--) { // 삼각형의 아래부터 반복을 돌음.위부터하면 많은 값을들 비교해야하므로 아래값부터 했음.

        for (int j = 0; j < triangle[i-1].size(); j++) {
            triangle[i - 1][j] += (triangle[i][j] > triangle[i][j + 1]) ? triangle[i][j] : triangle[i][j + 1]; // 자식 중 큰 값을 부모에게 더함.
        }

    }


    return answer = triangle[0][0];
}

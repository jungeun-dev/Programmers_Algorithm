#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> cut;

    for (vector<int> vec : commands) {
        for (int i = vec[0]; i <= vec[1]; i++) {
            cut.push_back(array[i - 1]);
        }
        sort(cut.begin(), cut.end()); // 오름차순 정렬
        answer.push_back(cut[vec[2] - 1]); // k번째 위치 -> k-1인덱스
        cut.clear();
    }

    return answer;
}
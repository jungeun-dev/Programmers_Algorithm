#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> arr : commands) {
        vector<int> sort_array(array.begin() + arr[0] - 1, array.begin() + arr[1]); // commands에서 말한 인덱스의 수 가져오기 [2,5,3]일 경우 2에서 5까지의 숫자를 가져옴.
        sort(sort_array.begin(), sort_array.end()); // 정렬
        answer.push_back(sort_array[arr[2] - 1]); // 숫자 가져오기.
    }

    return answer;
}

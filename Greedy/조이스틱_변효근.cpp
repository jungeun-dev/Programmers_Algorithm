#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//정답 예제 공부!

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };  // 알파벳을 조작순서에 맞춰 배열로 만듬.

int solution(string name) {
    int answer = 0;
    for (auto ch : name)
        answer += LUT[ch - 'A']; // 우선 answer에 ↑ ↓ 이 두 개의 버튼으로 조작할 내용들을 더함
    int len = name.length();
    int left_right = len - 1;
    for (int i = 0; i < len; ++i) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A') // A가 아닌 지점의 인덱스를 찾기.
            next_i++;
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
        // 그 인덱스에서 왼쪽으로 갔다 오른쪽으로 가는것이 빠른지 , 오른쪽에서 왼쪽으로 가는게 빠른지를 정함.
    }
    answer += left_right; // min 함수를 이용하여 가장 적은 값이 left_right에 넣어질 것임.
    return answer;
}

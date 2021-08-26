#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    string answer = "";
    int cnt = k;
    int t;

    // 논리
    // t는 문자의 인덱스를 저장한다.
    // t의 문자가 바로 뒤의 문자보다 작을 경우 그 해당문자를 삭제
    // 해당 문자보다 뒤의 문자가 작을 경우 t+1


    while (cnt > 0) { // cnt는 k만큼 삭제 시키기 위해 카운팅하는 변수
        t = 0;
        if (number.size() < k - 1) k = number.size() - 1; // 혹시나 k가 클까봐 크기 조정
        while (t <= number.size() - 2) { //마지막 -1 문자까지 순회
            if (number[t] < number[t + 1]) { // 만약 t+1 문자보다 t의 문자가 작다면
                number = number.erase(t,1);  // 그 값을 삭제
                break;
            }
            else t++;         // t+1 문자 < t 문자일 경우 t값을 증가
            if (t == number.size() - 2) {         // t가 맨 마지막-1 일 경우
                if (number[t] > number[t + 1]) {  // 이 경우 숫자는 내림차순이므로 k만큼 다 삭제
                    number = number.substr(0, t + 1 - cnt);
                    cnt = 0;
                }
                else number = number.erase(t,1); // 마지막만 큰 경우
            }
        }
        cnt--; 
    }

    return answer = number;
}

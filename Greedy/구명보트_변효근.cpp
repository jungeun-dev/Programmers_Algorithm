#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    // 이 문제는 2명씩 탈 수 있는 구명보트에 사람을 태우는 문제인데
    // 가장 무거운 사람과 가장 가벼운 사람을 알차게 태워야 한다.

    sort(people.begin(), people.end()); // 정렬 시킴.

    int start = 0;               // 가장 가벼운 사람의 인덱스를 나타내는 변수
    int end = people.size()-1;   // 가장 무거운 사람의 인덱스를 나타내는 변수

    while (start < end) {
        if (people[start] + people[end--] <= limit) {
          // 만약 가장 무거운 사람과 가장 가벼운 사람이 같이
          // 구명보트에 탈 수 있을 경우에 start를 추가시켜줌.
            start++;
        }
        answer++; //
    }
    if (start == end)answer++;
    return answer;
}

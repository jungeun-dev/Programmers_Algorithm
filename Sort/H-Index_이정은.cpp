#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//헷갈렸던 부분 h가 배열 안의 수가 아닐 수 있다는 것

int solution(vector<int> citations) {
    int cnt;
    int i, j;
    sort(citations.begin(), citations.end(), greater<int>()); //내림차순 정렬

    for (i = citations.size(); i >= 0; i--) { // h 가 될수 있는 가장 큰수부터 탐색
        cnt = 0;
        for (j = 0; j < citations.size(); j++) { // i번 이상 인용된 논문이 몇편인지 확인
            if (citations[j] >= i) cnt++;
        }
        if (cnt >= i) return i; 

    }
}
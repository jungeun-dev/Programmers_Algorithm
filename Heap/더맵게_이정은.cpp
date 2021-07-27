#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int a = 0, b;
    priority_queue <int, vector<int>, greater<int> > pq;

    for (int k : scoville) {
        pq.push(k);
    }
    a = pq.top(); // 가장 맵지 않은 음식의 스코빌 지수
    while (a < K) {
        pq.pop();
        if (pq.size() == 0) return -1; // k이상으로 못만듦 -> -1 반환
        b = pq.top(); // 두 번째로 맵지 않은 음식의 스코빌 지수
        pq.pop();
        a += (2 * b); // 섞음
        pq.push(a);  // 다시 집어넣음

        a = pq.top(); // 가장 맵지 않은 음식의 스코빌 지수
        answer++;
    }

    return answer;
}
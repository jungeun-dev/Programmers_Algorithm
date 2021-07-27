#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    // priority queue 우선순위 큐
    // queue의 형태를 갖지만 우선순위를 토대로 out 시킴.
    // 위의 pq는 오름차순 우선순위큐
    for (int i = 0;i < scoville.size();i++)
        pq.push(scoville[i]);
        // 주어진 값들을 우선순위 큐에 넣음
        // 이때 값이 들어갈 때마다 정렬됨.

    while (pq.size() >=2 && pq.top() < K) {
        int a = pq.top(); pq.pop(); // 정렬되어 있는 queue에서 가장 작은 앞의 값을 꺼냄.
        int b = pq.top(); pq.pop(); // 가장 앞의 값을 꺼냄. (실질적으론 2번째 값)

        pq.push(a + (2 * b)); // 다시 스코빌 지수 계산 후 pq에 넣음.

        answer++;
    }

    if (pq.size() <= 1 && pq.top() < K) return -1;
    return answer;
}

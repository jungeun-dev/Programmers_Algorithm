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
    a = pq.top(); // ���� ���� ���� ������ ���ں� ����
    while (a < K) {
        pq.pop();
        if (pq.size() == 0) return -1; // k�̻����� ������ -> -1 ��ȯ
        b = pq.top(); // �� ��°�� ���� ���� ������ ���ں� ����
        pq.pop();
        a += (2 * b); // ����
        pq.push(a);  // �ٽ� �������

        a = pq.top(); // ���� ���� ���� ������ ���ں� ����
        answer++;
    }

    return answer;
}
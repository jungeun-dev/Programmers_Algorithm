#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//dfs�� Ǯ�� �ﰢ�� ���� ��Ȳ���� ���� �߻� (1->3)(1->2)(3->2) �� ���� ��Ȳ
//bfs => �ִܰ�� ,�̷�ã�� ������ <= queue �̿�

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    vector<int> distance(n + 1, 0);

    //����� ����
    for (vector<int> e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int start = q.front();
        q.pop();

        for (int i = 0; i < graph[start].size(); i++) {
            int end = graph[start][i];
            if (!visited[end]) {
                visited[end] = true;
                distance[end] = distance[start] + 1;
                q.push(end);
            }
        }
    }

    sort(distance.rbegin(), distance.rend()); //�������� ����
    for (int d : distance) {
        if (d == distance[0]) answer++;
        else break;
    }

    return answer;
}
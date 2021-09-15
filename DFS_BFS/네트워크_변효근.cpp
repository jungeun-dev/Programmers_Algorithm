#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;


int bfs(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);            // 방문했는지의 여부를 판정하는 벡터
    queue<int> vertex;                       // queue



    // 진행방식
    // 3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	2 경우
    // 첫번째  vertex에 진입 후
    // 그 vertex와 연결된 vertex를 queue에 넣음.
    // 금방 넣은 vertex와 연결될 vertex를 또 넣음.
    // queue에 넣을 때 마다 방문했다는 것을 위해 visit벡터의 해당 인덱스 값을 true로 바꿈
    // 그렇게 되면 연결된 모든 vertex를 돌 것임.


    for (int i = 0; i < n; i++)
    {
        if (visit[i] == true) continue;
        vertex.push(i);
        while (!vertex.empty())
        {
            int v = vertex.front();
            cout << "vertex : " << v << endl;
            vertex.pop();
            visit[v] = true;
            for (int i = 0; i < n; i++) {
                if (computers[v][i] == 1 && visit[i] == false) vertex.push(i);
            }
        }
        answer++;
    }


    return answer;
}

void dfs(int n, vector<vector<int>> computers, vector<bool> &visit) {


    // BFS는 말 그대로 넗게 이용됬다면
    // DFS는 계속 깊게 들어감.

    // 1 -> 2,3
    // 2 -> 4,5
    // 인 경우를 생각했을때
    // BFS -> 1,2,3,4,5
    // DFS -> 1,2,4,5,3

    for (int i = 0; i < computers[n].size(); i++)
    {
        if (computers[n][i] == 1 && visit[i] == false) {
            visit[i] = true;
            //cout << "vertex : " << i << endl;
            dfs(i, computers, visit);
        }

    }


}


int solution(int n, vector<vector<int>> computers) {
    //int answer = bfs(n,computers);
    int answer = 0;
    vector<bool> visit(n, false);

    for (int i = 0; i < n; i++) {
        if (visit[i] == true) continue;
        visit[i] = true;
        cout << "vertex : " << i << endl;
        dfs(i, computers, visit);
        answer++;
    }

    return answer;
}

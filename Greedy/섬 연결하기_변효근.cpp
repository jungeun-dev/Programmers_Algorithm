#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 이 문제는 그래프 문제로
// MST 최소 신장 트리를 만드는 문제이다.
// 크루스칼 알고리즘을 이용하여 문제를 풀었다.

int getParent(vector<int> set, int x) { // 부모를 찾는 함수.
    if (set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}
vector<int> unionParent(vector<int> set, int a, int b) { // 부모를 합치는 함수.
    a = getParent(set, a); // a의 부모를 찾음.
    b = getParent(set, b); // b의 부모를 찾음.

    // 인덱스가 낮은 것을 부모로 하여 부모를 합침.
    if (a < b) set[b] = a;
    else set[a] = b;

    return set;
}

int find(vector<int> set, int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if (a == b) return 1;
    else return 0;
}

class Edge {    // 간선을 나타낼 클래스
    public :
        int start;         // 시작점
        int end;           // 끝점
        int distance;      // 가중치
        Edge(int a,int b,int distance) {
            this->start = a;
            this->end = b;
            this->distance = distance;
        }
        bool operator < (Edge& edge) {  // 정렬 방식 : 가중치 오름차순
            return this->distance < edge.distance;
        }
};
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<Edge> v;
    for (vector<int> c : costs) {
        v.push_back(Edge(c[0], c[1], c[2]));
        // 간선 생성.
    }
    sort(v.begin(), v.end());
    // 간선을 정렬함
    // 여기서 operator로 v는 가중치 오름차순으로 정렬될 것임.

    vector<int> set; // set은 부모를 저장할 벡터

    for (int i = 0; i < n; i++) {
        set.push_back(i); // 처음은 자기 자신이 부모.
    }

    for (int i = 0; i < v.size(); i++) {

        if (!find(set, v[i].start, v[i].end)) {
          // 부모를 찾아봄. 만약 부모가 같을 경우 이미 하나로 연결되있다는 말이므로
          // 부모가 다를 경우에만 if문이 실행됨.
            answer += v[i].distance;
            //간선들을 가중치 오름차순으로 정렬했기에
            //부모가 다를 경우 그 상태에서 가장 작은 간선이 연결됨.

            set = unionParent(set, v[i].start, v[i].end);
            // 부모를 하나로 합침.
        }
    }

    return answer;
}

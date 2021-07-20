#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    vector<int> timer(truck_weights.size(), 0); // 각 트럭마다 지나는 시간을 잴 vector, truck개수 만큼 선언하며 모두 0으로 초기화함.
    int bridge_weight = 0;  // 현재 다리에 올라가 있는 트럭들의 무게 총 합을 저장할 변수.
    int start=0, end=0;     // 맨 앞과 맨 뒤 트럭의 인덱스를 가르킬 변수.

    timer[end]++;                        // 첫 트럭을 먼저 다리에 올려둠.
    bridge_weight += truck_weights[end]; // 다리에 올라갔다는 의미는 bridge_weight에 무게를 추가시키고
                                         // timer가 매 시간마다 늘어남을 의미함.

    while (bridge_weight != 0) {
        if (timer[start] == bridge_length) {
            bridge_weight -= truck_weights[start++]; // 끝까지 도달한 애들 즉 시간이 다 된 애들은 뺀다.
        }
        if (end+1 != truck_weights.size() && bridge_weight + truck_weights[end+1] <= weight) { // 만약 현재 다리에 다음 트럭을 올릴 수 있다면
            bridge_weight += truck_weights[++end];
        }
        for (int i = start;i <= end;i++) timer[i]++;  // 매 시간마다 timer를 늘려줌.
        answer++;   //시간 추가
    }


    return answer;
}

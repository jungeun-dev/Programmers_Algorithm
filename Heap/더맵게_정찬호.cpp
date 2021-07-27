#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first;
    int second;
    int sum;
    priority_queue<int,vector<int>,greater<int>> q;
    //최소힙 선언
    for(int i=0;i<scoville.size();i++){
        q.push(scoville[i]);
    }
    //배열을 힙에 입력받기

    while(q.top()<K){
        first=q.top();
        q.pop();
        second=q.top();
        q.pop();
        sum=first+(second*2);
        q.push(sum);
        answer++;
        // 힙의 첫번째와 두번째를 뽑아내서 인자에 전달
        // 계산값을 다시 힙에 넣음 - 애초에 힙선언 자체를 최소힙으로 했기때문에 푸시를 해도 오름차순배열로 정렬
        if(q.size()==1&&q.top()<K){
            answer=-1;
            break;
        }
        // 만약 힙의 원소가 하나밖에없고 그 값이 k를 넘지 안는다면 answer에 -1을 넣고 break
    }


    return answer;
}

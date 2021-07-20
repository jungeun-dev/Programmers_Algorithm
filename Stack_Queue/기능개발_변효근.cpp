#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <int> queue;

    for (int i = 0;i < progresses.size();i++) {
        int max = 0;
        progresses[i] = (100 - progresses[i]);          // [93,30,55] -> [7,70,45] 형식으로 만듬.
        if (progresses[i] % speeds[i] != 0) max++;      // 이때 딱 나눠떨어지지 않으면 1을 더해줘야함. [7,3,9] 지만 나누기만하면 [7,2,9] 이므로
        max += progresses[i] / speeds[i];

        //progresses[i] /= ceil((float)speeds[i]);  하 이한줄로 되는데ㅠ 버전차이인듯

        queue.push(max); // queue에 넣음.
    }

    // 이 결과 queue 는 [7,3,9], [5,10,1,1,20,1] 형식일 것임.

    int num = 1;                      // 개수를 카운팅 할 변수
    int pivot = queue.front();        //queue 에서 가장 앞 데이터를 가져와서 기준점으로 삼음.
    queue.pop();
    while (queue.size()!=0) {
        int front = queue.front();    // 큐의 맨 처음 데이터를 가져옴.
        queue.pop();

        if (front > pivot) {         //  만약 맨 처음 데이터가 기존의 기준점 데이터보다 크다면
            answer.push_back(num);   //  그때까지 추가해준 num을 answer에 추가시키고
            pivot = front;           //  맨처음 데이터를 기준점으로 삼음.
            num = 0;                 //  num 초기화
        }
        num++;                       //  num ++
    }
    answer.push_back(num);
    return answer;
}

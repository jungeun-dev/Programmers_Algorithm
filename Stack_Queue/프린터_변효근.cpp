#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int i, int j) { return i > j; }
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> queue; // <key,value> 딕셔너리 형식의 큐를 생성

    for (int i = 0;i < priorities.size();i++) {
        queue.push(make_pair(i,priorities[i])); // <index , 값> 형태로 큐에 삽입
        // 예제의 값을 이용하여 [1,1,9,1,1,1]
        // <0,1>,<1,1>,<2,9>,<3,1>,<4,1>,<5,1> 형식으로 삽입됐을 것임.
    }
    
    vector<int> sorted_prior = priorities; // priorities를 정렬한 상태를 sorted_prior에 저장하려함.

    sort(sorted_prior.begin(), sorted_prior.end(), compare); // compare의 방식으로 정렬함 => 내림차순 [9,1,1,1,1,1]

    for (auto i = sorted_prior.begin();i != sorted_prior.end();++i) { // sorted_prior의 값을 하나씩 가져옴.
        while (true)
        {
            //1 1
            pair<int, int> front = queue.front(); // 큐의 데이터를 맨앞에서 하나씩 꺼냄.
            queue.pop();
            if (front.second == *i) {            // 만약 큐의 맨 앞에 데이터가 가장 큰 숫자일 경우
                if (front.first == location) {   // 가장 큰 수이면서 location이 가리키는 숫자인 경우
                    return answer+1;             // return함.
                }
                else {                           // 만약 큐의 맨 앞에 데이터가 가장 큰수이지만
                    answer++;                    // location이 가리키는 숫자가 아닌 경우
                    break;                       // 그 값을 queue에서 빼고 다음으로 넘어감.
                }
            }
            else {                               // 큐의 맨 앞의 데이터가 가장 큰수가 아닐 경우
                queue.push(front);               // 큐의 맨뒤에 다시 데어터를 삽입함.
            }
        }
    }
    return answer;
}

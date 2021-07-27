#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
};
//이차원 배열에서 실행시간이 짧은 시간먼저 정렬

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time=0;
    int i=0;
    sort(jobs.begin(), jobs.end());
    //작업요청이 빠른순으로 정렬 이차원배열의 [0]요소
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare> q;
    //우선순위큐에pair을 넣으면 원소에 여러자료가들어감 여기서는 이차원배열을 넣음

    while(i<jobs.size()||!q.empty()){
        if(i<jobs.size()&&jobs[i][0]<=time){
            q.push({jobs[i][0],jobs[i][1]});
            i++;
            continue;
        }
        //조건만족시 계속 이 if문을 수행

        if(!q.empty()){
            time+=q.top().second;
            answer+=time-q.top().first;
            q.pop();
        }
        //위에조건이 만족이 안될경우 즉, time<jobs[i]일경우 큐에 있는 값 계산 큐가 빌때 까지
       else{
           time=jobs[i][0];
       }
       //시간을 다음작업으로 변경
    }

    return answer/jobs.size();
}

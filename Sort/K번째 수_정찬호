#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for (int i = 0;i < commands.size();i++) {
        for (int j = commands[i][0];j <= commands[i][1];j++) {
            temp.push_back(array[j-1]);
            //푸시백 함수로 temp벡터에 array벡터의 원소 입력
        }
        sort(temp.begin(), temp.end()); // 원하는범위의 요소를 받은 벡터 오름차순으로 정렬
        //벡터요소처음의 주소값을 반환하는begin(),벡터요소의 끝부분+1 주소값을 반환하는end()
        answer.push_back(temp[commands[i][2]-1]);
        //answer벡터에 temp벡터의 값 중 문제에서 요구하는 값 찾아서 넣기
        temp.clear();
        //temp벡터 초기화
    }
    return answer;
}

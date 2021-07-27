#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;

    string s;
    int a;
    for (string str : operations) {
        s = str[0]; //문자열의 0번째
        a = stoi(str.substr(2)); //문자열의 2번째부터 숫자로 변환 
        if (s == "I") { //추가하는 경우
            dq.push_back(a);
            sort(dq.begin(), dq.end()); //오름차순 정렬
        }
        else if (s == "D") { //삭제하는 경우
            if (dq.size() > 0) {
                if (a == 1) dq.pop_back();//최댓값 삭제               
                else dq.pop_front(); //최솟값 삭제                
            }
        }
    }
    if (dq.empty()) { // 빈경우
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back()); // 최대값 삽입
        answer.push_back(dq.front()); // 최소값 삽입        
    }
    return answer;
}

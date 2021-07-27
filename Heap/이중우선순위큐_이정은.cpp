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
        s = str[0]; //���ڿ��� 0��°
        a = stoi(str.substr(2)); //���ڿ��� 2��°���� ���ڷ� ��ȯ 
        if (s == "I") { //�߰��ϴ� ���
            dq.push_back(a);
            sort(dq.begin(), dq.end()); //�������� ����
        }
        else if (s == "D") { //�����ϴ� ���
            if (dq.size() > 0) {
                if (a == 1) {//�ִ� ����
                    dq.pop_back();
                }
                else { //�ּڰ� ����
                    dq.pop_front();
                }
            }
        }
    }
    if (dq.empty()) { // ����
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back()); // �ִ밪 ����
        answer.push_back(dq.front()); // �ּҰ� ����        
    }
    return answer;
}
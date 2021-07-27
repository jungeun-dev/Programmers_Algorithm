#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int total = 0;
    int i;
    vector <pair <int, int>> js;

    for (int i = 0; i < jobs.size(); i++) {
        js.push_back(make_pair(jobs[i][1], jobs[i][0])); // <�۾� �ҿ� �ð�, �۾� ��û �ð�>
    }
    sort(js.begin(), js.end()); // �۾� �ҿ�ð� ������������ ���ĵ�

    while (!js.empty()) {
        for (i = 0; i < js.size(); i++) {
            if (js[i].second <= total) { // �۾� ��û�ð��� ���� �ð����� �������
                total += js[i].first;
                answer += (total - js[i].second);
                js.erase(js.begin() + i);
                break;
            }
            if (i == js.size() - 1) total++;
        }
        //if(i == js.size()) total++;        
    }

    answer /= jobs.size(); //�ɸ��ð� ���
    return answer;
}
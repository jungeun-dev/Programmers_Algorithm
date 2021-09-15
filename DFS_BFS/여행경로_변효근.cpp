#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> a;

void dfs(string root, vector<vector<string>> tickets,vector<bool> visit) {
    if (count(visit.begin(),visit.end(),true)==visit.size()) { //모든 곳을 다 경유 했을 경우
        a.push_back(root);                                     // root를 a에 저장
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        string start = root.substr(root.size() - 3);           //string root는 지나온 경로들을 이어서 붙은 string이므로 마지막 경유지, 즉 마지막 3글자가 마지막 도착지이다.
        if (start.compare(tickets[i][0])==0 && visit[i] == false) {// 다음 경유지의 글자가 마지막 도착지의 글자와 같다면,
            root += tickets[i][1];                                 // root에 concat해줌.
            visit[i] = true;                                       // 모든 경로를 dfs 선언 전 true 선언 이후 false
            dfs(root, tickets, visit);
            visit[i] = false;
        }
    }
    return;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    vector<bool> visit(tickets.size(), false);

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0].compare("ICN") == 0) {
            string root = tickets[i][0] + tickets[i][1];
            visit[i] = true;
            dfs(root, tickets, visit);
            visit[i] = false;
        }
    }
    sort(a.begin(), a.end());
   while (a[0].size() > 3)
    {
        answer.push_back(a[0].substr(0,3));
        a[0] = a[0].substr(3);
    }
    answer.push_back(a[0]);
    return answer;
}

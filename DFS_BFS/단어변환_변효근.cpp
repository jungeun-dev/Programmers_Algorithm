#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a = 10000;

bool CanChange(string begin, string word) {     //변환이 가능한지를 판단하는 함수
    int cnt = 0;                                // hit -> hot 일 경우 true 리턴
    for (int i = 0; i < begin.size(); i++) {    // hit -> cog 일 경우 false 리턴
        if (begin.at(i) != word.at(i)) cnt++;
    }
    if (cnt == 1) return true;
    else return false;

}

void dfs(string begin, string target, vector<string> words, vector<bool> visit) {
    if (target == begin && count(visit.begin(), visit.end(), true) < a) {  // 해당 문자가 변환이 가능할 경우 최솟값을 위한 조건
        a = count(visit.begin(), visit.end(), true);
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (CanChange(begin,words[i]) && visit[i] == false) { // 변환 가능 할 경우
            visit[i] = true;                        // 해당 재귀에서만 true표시로 남도록 true로 바꿔준 후
            dfs(words[i], target,words, visit);     // dfs 선언 후
            visit[i] = false;                       // 다시 false로
        }
    }


}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visit(words.size(), false);
    dfs(begin, target, words, visit);
    if (a != 10000) return answer = a;
    else return answer = 0;
}

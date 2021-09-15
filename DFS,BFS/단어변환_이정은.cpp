#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 51;

bool cmp(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) cnt++;
    return cnt == 1;
}
void DFS(string str, string target, vector<bool> check, vector<string> words, int cnt) {
    if (str == target) {
        if (answer > cnt) answer = cnt;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (cmp(str, words[i]) && !check[i]) {
            check[i] = true;
            DFS(words[i], target, check, words, cnt + 1);
            check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    vector<bool> check(words.size(), false);

    vector<string>::iterator it = find(words.begin(), words.end(), target);
    if (it != words.end()) {
        DFS(begin, target, check, words, 0);
    }
    else answer = 0;

    return answer;
}
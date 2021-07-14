#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define pp pair<string,int>
#define pp2 pair<int,int>

using namespace std;
bool compare(const pp2& a, const pp2& b) {
    //if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

bool cmp(const pp& a, const pp& b) {
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map <string, int> total;
    map <string, vector<pair<int, int>>> play_list;  //장르 <고유번호, 횟수>
    int size = genres.size();
    int k = 0;

    //total 수 정리
    for (int i = 0; i < size; i++) {
        total[genres[i]] += plays[i];
        play_list[genres[i]].push_back(make_pair(i, plays[i]));
    }

    //내림차순 정렬
    vector<pp> vec(total.begin(), total.end());
    sort(vec.begin(), vec.end(), cmp);

    for (auto v : vec) {
        sort(play_list[v.first].begin(), play_list[v.first].end(), compare);

        k = 0;
        for (auto a : play_list[v.first]) {
            if (k >= 2) break;
            answer.push_back(a.first);
            k++;
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end()); // 정렬 오름차순으로.

    int num = citations[citations.size()-1]; //가장 큰 수를 가져옴.

    while (true) {
        int cnt = 0;
        for (int i = citations.size()-1; i >=0; i--) {
            if (citations[i] >= num) cnt++; // 돌면서 n편 중, h번 이상 인용된 논문이 h편 이상인지를 확인하기 위해
        }
        if (cnt >= num) return answer = num;
        num--;
    }

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int a, b;
    for (int i = 1; i * i <= yellow; i++) {
        if (yellow % i == 0) {
            a = i + 2; // 세로
            b = yellow / i + 2; // 가로
            if (a * 2 + b * 2 - 4 == brown) {
                answer.push_back(b); answer.push_back(a);
                return answer;
            }
        }
    }
}

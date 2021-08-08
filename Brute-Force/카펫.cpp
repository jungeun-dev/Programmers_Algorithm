#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int j;
    for (int i = yellow;i >= 0;i--) {

        if (yellow % i == 0) {
            if ((i + 2) * 2 + (yellow / i) * 2 == brown) {
                answer.push_back(i + 2);
                answer.push_back((yellow / i) + 2);

                break;
            }
        }
    }
    return answer;
}

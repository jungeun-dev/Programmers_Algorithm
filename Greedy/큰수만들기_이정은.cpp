#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int tmp = -1;

    for (int i = number.size() - k; i > 0; i--) {
        char max = '0';
        for (int j = tmp + 1; j <= number.size() - i; j++) {
            if (max < number[j]) {
                max = number[j];
                tmp = j;
            }
        }
        answer += max;
    }
    return answer;
}
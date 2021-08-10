#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> times) {
    unsigned long long answer = 0, mid;
    long long start, end;
    long long num;
    int size = ceil(n / times.size());
    end = *max_element(times.begin(), times.end()) * size; // 최대 시간
    start = *min_element(times.begin(), times.end()) * size; // 최소 시간

    while (end >= start) {
        mid = (start + end) / 2;    //중앙 값
        num = 0;
        for (int i = 0; i < times.size(); i++) { // mid 시간동안 처리가능한 사람수
            num += mid / times[i];
        }
        if (num >= n) {
            if (answer == 0) { answer = mid; }
            else { answer = min(answer, mid); }
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return answer;
}
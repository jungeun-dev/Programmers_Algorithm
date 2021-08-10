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
    end = *max_element(times.begin(), times.end()) * size; // �ִ� �ð�
    start = *min_element(times.begin(), times.end()) * size; // �ּ� �ð�

    while (end >= start) {
        mid = (start + end) / 2;    //�߾� ��
        num = 0;
        for (int i = 0; i < times.size(); i++) { // mid �ð����� ó�������� �����
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
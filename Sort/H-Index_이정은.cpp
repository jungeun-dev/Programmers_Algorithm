#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//�򰥷ȴ� �κ� h�� �迭 ���� ���� �ƴ� �� �ִٴ� ��

int solution(vector<int> citations) {
    int cnt;
    int i, j;
    sort(citations.begin(), citations.end(), greater<int>()); //�������� ����

    for (i = citations.size(); i >= 0; i--) { // h �� �ɼ� �ִ� ���� ū������ Ž��
        cnt = 0;
        for (j = 0; j < citations.size(); j++) { // i�� �̻� �ο�� ���� �������� Ȯ��
            if (citations[j] >= i) cnt++;
        }
        if (cnt >= i) return i; 

    }
}